
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
     *@brief 按照指定的分隔符，对传入的字符串进行切分
     *@param [in/out] str   : const std::string
     *@param [in/out] separator   : const std::string
     *@return  std::vector<std::string> 
     *@author wangweizhu
     **/
    std::vector<std::string> split_string_by_separator(const std::string str, 
            const std::string separator);

    /**
     *@brief 逐行读取词表文件，并对每一行数据进行解析  
     *@param [in/out] file_name   : const std::string
     *@return  int
     *@author wangweizhu 
     **/
    int read_file_by_line(const std::string file_name);  

    /**
     *@brief 读取词表文件的第一行，得到每一列数据的数据类型
     *@param [in/out] first_line_str   : const std::string 
     *@return  int
     *@author wangweizhu
     **/
    int get_each_col_data_type(const std::string first_line_str);

    /**
     *@brief 对一行中的某一列数据进行解析
     *@param [in/out] col_str   : const std::string    
     *@param [in/out] index   : const int ,表示是第几列数据
     *@return  int 
     *@author wangweizhu
     **/
    int col_str_data_parser(const std::string col_str, const int index, const int line); 
private:
    int _total_col_cnt;       /**< 词表文件的总列数 */     
    std::vector<std::string> _each_col_data_type;         /**< 每一列的数据类型 */  
    std::vector<std::string> _cur_line_str_vec;       /**< 存储对一整行数据切分好的结果 */   
    std::map<std::string, IData*> _str_to_idata_map;    /**< 数据类型的字符串与解析类型的映射*/    

};
}
}

#endif  //GOODCODER_DENGJIAHAO_DICT_PARSER_H     
