#include "user_data.h" 
#include "buildin_data.h"
#include <vector>
#include <errno.h>   
#include "define_func.h"   

namespace wangweizhu {
namespace dict_parser {

namespace user_data {
std::vector<std::string> split_string_by_separator(const std::string str,  
        const std::string separator) {
    std::vector<std::string> res;  
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
}

int UserData::data_parser(const std::string& str) {
    std::vector<std::string> split_array =   
        user_data::split_string_by_separator(str, _str_separator);  
    int array_size = split_array.size();  
    
    if (array_size != get_member_cnt()) {
        FATAL("user_data size incorrect");    
        return -1; 
    }
    // name
    _name = split_array[0];
    // age
    char* p_end = NULL;  
    long int ret_li = strtol(split_array[1].c_str(), &p_end, 10);  
    if (errno != 0 || *p_end != '\0') {
        FATAL("user_data parse fail");
        return -1; 
    }

    _age = static_cast<int>(ret_li);    
    // kill
    p_end = NULL;
    float ret_f = strtof(split_array[2].c_str(), &p_end);   
    if (errno != 0 || *p_end != '\0') {
        FATAL("user_data parse fail");  
        return -1;
    }

    _kill = static_cast<float>(ret_f);  
    // dead
    p_end = NULL;  
    ret_f = strtof(split_array[3].c_str(), &p_end);      

    if (errno != 0 || *p_end != '\0') {
        FATAL("user_data parse fail");  
        return -1;        
    }

    _dead = static_cast<float>(ret_f);  

    // assist
    p_end = NULL;   
    ret_f = strtof(split_array[4].c_str(), &p_end);   
    if (errno != 0 || *p_end != '\0') {
        FATAL("user_data parse fail");   
        return -1;        
    }

    _assist = static_cast<float>(ret_f);   
    return 0;
}

}
}
