
#ifndef GOODCODER_WANGWEIZHU_DICT_PARSER_H 
#define GOODCODER_WANGWEIZHU_DICT_PARSER_H

#include "idata.h" 
#include "user_data.h"
#include "buildin_data.h"  
 
#include <string>  
#include <vector>
#include <map>

namespace wangweizhu {
namespace dict_parser {

class IData;
class DictParser {
public:
    DictParser(); 
    ~DictParser();  
    /**
     *@brief ����ָ���ķָ������Դ�����ַ��������з�
     *@param [in/out] str   : const std::string
     *@param [in/out] separator   : const std::string
     *@return  std::vector<std::string> 
     *@author wangweizhu
     **/
    std::vector<std::string> split_string_by_separator(const std::string str, 
            const std::string separator);

    /**
     *@brief ���ж�ȡ�ʱ��ļ�������ÿһ�����ݽ��н���  
     *@param [in/out] file_name   : const std::string
     *@return  int
     *@author wangweizhu 
     **/
    int read_file_by_line(const std::string file_name);  

    /**
     *@brief ��ȡ�ʱ��ļ��ĵ�һ�У��õ�ÿһ�����ݵ���������
     *@param [in/out] first_line_str   : const std::string 
     *@return  int
     *@author wangweizhu
     **/
    int get_each_col_data_type(const std::string first_line_str);

    /**
     *@brief ��һ���е�ĳһ�����ݽ��н���
     *@param [in/out] col_str   : const std::string    
     *@param [in/out] index   : const int ,��ʾ�ǵڼ�������
     *@return  int 
     *@author wangweizhu
     **/
    int col_str_data_parser(const std::string col_str, const int index, const int line); 
private:
    int _total_col_cnt;       /**< �ʱ��ļ��������� */     
    std::vector<std::string> _each_col_data_type;         /**< ÿһ�е��������� */  
    std::vector<std::string> _cur_line_str_vec;       /**< �洢��һ���������зֺõĽ�� */   
    std::map<std::string, IData*> _str_to_idata_map;    /**< �������͵��ַ�����������͵�ӳ��*/    

};
}
}

#endif  //GOODCODER_DENGJIAHAO_DICT_PARSER_H     
