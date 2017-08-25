
#include "dict_parser.h" 
#include "define_func.h"
#include "user_data.h"
#include <fstream>
#include <string> 

namespace wangweizhu {
namespace dict_parser {
DictParser::DictParser() :  
    _total_col_cnt(0), 
    _each_col_data_type(0, ""),    
    _cur_line_str_vec(0, "") {
        //��ʼ������ӳ���ϵ  
        _str_to_idata_map["int"] = new(std::nothrow) IntData();  
        _str_to_idata_map["float"] = new(std::nothrow) FloatData();  
        _str_to_idata_map["string"] = new(std::nothrow) StrData();      
        _str_to_idata_map["int_array"] = new(std::nothrow) IntArrayData(); 
        _str_to_idata_map["float_array"] = new(std::nothrow) FloatArrayData();
        _str_to_idata_map["str_array"] = new(std::nothrow) StrArrayData();  
        _str_to_idata_map["user_data"] = new(std::nothrow) UserData(); 
    }

DictParser::~DictParser() {
    std::map<std::string, IData*>::iterator it; 
    for (it = _str_to_idata_map.begin(); it != _str_to_idata_map.end(); ++it) {
          IData* ptr = static_cast<IData*>((*it).second);    
          if (ptr) {
              delete ptr;  
              (*it).second = 0;  
          }
    }
}

std::vector<std::string> DictParser::split_string_by_separator(const std::string str,   
        const std::string separator) {
    //����ָ���ķָ������ַ��������з�  
    std::vector<std::string> res(0, "");  
    std::size_t start_index = 0;  
    std::size_t end_index = str.find_first_of(separator);  

    while (end_index != std::string::npos) {
        std::string temp_str = str.substr(start_index, end_index - start_index);
        
        if (temp_str.size() > 0) {
            res.push_back(temp_str); 
            
        }
        start_index = end_index + 1; 
        
        end_index = str.find_first_of(separator, start_index);  
    }

    if (start_index < str.size()) {
        std::string last_str = str.substr(start_index);
        res.push_back(last_str); 
    }

    return res;
}

int DictParser::read_file_by_line(const std::string file_name) {
    std::ifstream data_file;  
    data_file.open(file_name.c_str(), std::ifstream::in); 
    //�ļ�����ʧ��    
    if (data_file.fail()) {
         FATAL("Open file error");
         return -1;
    }
    std::string cur_line_str = ""; 
    int line = 0;   
    //���ж�ȡ���� 
    while (getline(data_file, cur_line_str)) {
        if (line == 0) {
            //��һ�л�ȡÿһ�е���������   
            ++line;
            int ret = get_each_col_data_type(cur_line_str); 
            if (ret == -1) {
                return -1; 
            }
        }
        else {
            //�ڶ��п�ʼ���н���
            printf("\n");
            ++line; 
            printf("line:%d,\n", line - 1);    
            if (cur_line_str.size() == 0) {
                 FATAL("line %d of data.conf is empty", line - 1);  
                 continue;
            }

            std::vector<std::string> each_col_data_value = 
                split_string_by_separator(cur_line_str, "\t");  
            int cur_line_cnt = each_col_data_value.size();
            //���������������һ�е�����������ƥ��  
            if (cur_line_cnt != _total_col_cnt) {
                FATAL("line %d's columns_number incorrect", line - 1); 
                continue;     
            }

            for (int i = 0; i < cur_line_cnt; ++i) {
                //��ÿһ�����ݽ��н���
                printf("col: %d ", i + 1); 
                std::string cur_col_data_str = each_col_data_value[i];
                if (cur_col_data_str.size() == 0) {
                     FATAL("line %d,column %d is empty", line - 1, i + 1);  
                     continue; 
                }
                int res = col_str_data_parser(cur_col_data_str, i, line);    
                printf("\n");
                if (res == -1) {
                    continue;
                }
            }
        }
    }
    if (line == 0) {
        WARNING("data.conf is empty");  
        return -1;
    }
    data_file.close(); 
    return 0; 

}

int DictParser::get_each_col_data_type(const std::string first_line_str) {
    //���ݴʱ��ļ��ĵ�һ�У���ȡÿһ�е���������     
    if (first_line_str.size() == 0) {
        WARNING("data.conf is empty"); 
        return -1;
    }
    _each_col_data_type = split_string_by_separator(first_line_str, "\t"); 
    //�жϴ�����Ƿ�Ϊ���������ַ��� 
    if (_each_col_data_type[0][0] != '#') {
        FATAL("line 1 of data.conf format error"); 
        return -1;     
    }
    _each_col_data_type[0].erase(0, 1);  
    printf("%d %s\n", _each_col_data_type.size(), _each_col_data_type[0].c_str()); 
    std::map<std::string, IData*>::iterator iter;  

    for (std::size_t i = 0; i < _each_col_data_type.size(); ++i) {
        std::string cur_str = _each_col_data_type[i];  
        iter = _str_to_idata_map.find(cur_str);
        //��ӳ�����û�ҵ������ͣ�����������������ͷǷ�     
        if (iter == _str_to_idata_map.end()) {
            FATAL("line 1,column %d is illegal date type", (int)(i + 1)); 
            return -1; 
        }
    }

    _total_col_cnt = _each_col_data_type.size();
    return 0;
}

int DictParser::col_str_data_parser(const std::string cur_col_data_str, 
        const int index,
        const int line) {
    //��������ַ������н��� 
    std::string cur_col_data_type = _each_col_data_type[index];              
    std::map<std::string, IData*>::iterator it = _str_to_idata_map.find(cur_col_data_type); 
    //�Ҳ�����Ӧ��ӳ���ϵ  
    if (it == _str_to_idata_map.end()) {
        FATAL("line %d,column %d is illegal data type", line - 1, index + 1);   
        return -1;  
    }
    int ret = it->second->data_parser(cur_col_data_str);  
    //����ʧ��  
    if (ret == -1) {
        FATAL("line %d,column %d parse error", line - 1, index + 1); 
        return -1;   
    }
    it->second->print_data(); 
    return 0;
}
}
}
