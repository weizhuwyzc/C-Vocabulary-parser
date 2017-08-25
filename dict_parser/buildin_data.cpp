#include "buildin_data.h"
#include <iostream>  
#include <stdlib.h> 
#include <errno.h>
#include <define_func.h>

namespace wangweizhu {
namespace dict_parser {

int IntData::data_parser(const std::string& str) {
    char* p_end = NULL; 
    long int ret_li = strtol(str.c_str(), &p_end, 10);

    if (errno != 0 || *p_end != '\0') {
        FATAL("data format error");   
        return -1;        
    }

    int input_data = static_cast<int>(ret_li);     
    set_data_value(input_data); 

    return 0;
}

int FloatData::data_parser(const std::string& str) {
    char* p_end = NULL; 
    float ret_f = strtof(str.c_str(), &p_end);  
    if (errno != 0 || *p_end != '\0') {
        FATAL("data format error");      
        return -1;      
    }

    float input_data = static_cast<float>(ret_f);   
    set_data_value(input_data);  

    return 0; 
}

int StrData::data_parser(const std::string& str) {
    set_data_value(str);  

    return 0; 
}

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

int IntArrayData::data_parser(const std::string& str) {
    std::vector<std::string> array_split_vec = split_string_by_separator(str, ":");
    if (array_split_vec.size() != 2) {
        FATAL("int[] data format illegal"); 
        return -1;   
    } 

    char* p_end = NULL; 
    long int ret_li = strtol(array_split_vec[0].c_str(), &p_end, 10);
    if (errno != 0 || *p_end != '\0') {
        FATAL("fail to get int[] data size");      
        return -1;       
    }
    std::size_t vec_size = static_cast<std::size_t>(ret_li); 
    std::vector<std::string> int_array = split_string_by_separator(array_split_vec[1].c_str(), ",");   
    if (int_array.size() != vec_size) {
        FATAL("int[] data size incorrect");  
        return -1;
    } 
    std::vector<int> res;     

    for (std::size_t i = 0; i < vec_size; ++i) {
        char* p_end = NULL;  
        long int ret_li = strtol(int_array[i].c_str(), &p_end, 10);  
        if (errno != 0 || *p_end != '\0') {
            FATAL("int[] element parse error");    
            return -1;          
        }

        int temp_data = static_cast<int>(ret_li);
        res.push_back(temp_data);
    }

    set_data_value(res); 

    return 0; 
}

int FloatArrayData::data_parser(const std::string& str) {
    std::vector<std::string> array_split_vec = split_string_by_separator(str, ":");  
    if (array_split_vec.size() != 2) {
        FATAL("float[] data format illegal"); 
        return -1;
    }
    char* p_end = NULL; 
    long int ret_li = strtol(array_split_vec[0].c_str(), &p_end, 10);  

    if (errno != 0 || *p_end != '\0') {
        FATAL("fail to get float[] data size"); 
        return -1;  
    }
    std::size_t vec_size = static_cast<std::size_t>(ret_li); 
    std::vector<std::string> float_array =  
        split_string_by_separator(array_split_vec[1].c_str(), ",");     
    if (float_array.size() != vec_size) {
        FATAL("float[] data size incorrect");
        return -1;  
    }

    std::vector<float> res; 
    for (std::size_t i = 0; i < vec_size; ++i) {
        char* p_end = NULL; 
        float ret_f = strtof(float_array[i].c_str(), &p_end);    
        if (errno != 0 || *p_end != '\0') {
            FATAL("int[] element parse error"); 
            return -1;           
        }

        float temp_data = static_cast<float>(ret_f); 
        res.push_back(temp_data);    
    }

    set_data_value(res);    
    return 0;   
}

int StrArrayData::data_parser(const std::string& str) {
    std::vector<std::string> array_split_vec = split_string_by_separator(str, ":");  

    if (array_split_vec.size() != 2) {
        FATAL("string[] data format illegal"); 
        return -1;  
    }

    char* p_end = NULL;  
    long int ret_li = strtol(array_split_vec[0].c_str(), &p_end, 10);    
    if (errno != 0 || *p_end != '\0') {
        FATAL("fail to get string[] data size");   
        return -1;         
    }

    std::size_t vec_size = static_cast<std::size_t>(ret_li);      
    std::vector<std::string> string_array =      
        split_string_by_separator(array_split_vec[1].c_str(), ",");   
    if (string_array.size() != vec_size) {
        FATAL("string[] data size incorrect");    
        return -1;   
    }

    set_data_value(string_array); 
    return 0; 
}

}
}
