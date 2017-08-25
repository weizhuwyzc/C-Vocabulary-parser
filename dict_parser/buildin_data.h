#ifndef GOODCODER_WANGWEIZHU_BUILDIN_DATA_H
#define GOODCODER_WANGWEIZHU_BUILDIN_DATA_H

#include "idata.h"  
#include "data_type.h"
#include <iostream> 
#include <string> 
#include <vector>  

namespace wangweizhu {
namespace dict_parser {
/**
 *@brief 整数类型 
 **/
class IntData : public IData {
public:
    IntData() : _data_value(0) {}
    ~IntData() {}
    /**
     *@brief 返回解析的数据类型 
     *
     *@return  Datatype
     *@author wangweizhu
     **/
    Datatype data_type() {
        return INT; 
    }
    /**
     *@brief 打印解析的数据
     *@return  void
     **/
    void print_data() {
        printf("(int)%d ", _data_value);
    }

    /**
     *@brief 存储解析的数据   
     *@param [in/out] input_data   : int    
     *@return  void
     **/
    void set_data_value(int input_data) {
        _data_value = input_data; 
    }

    /**
     *@brief 解析整数类型的数据
     *@param [in/out] str   : const std::string
     *@return  int
     **/
    int data_parser(const std::string& str); 
private:
    int _data_value;          /**< 用于存储解析成功的数据 */     

};

/**
 *@brief 小数类型  
 **/
class FloatData : public IData {
public:
    FloatData() : _data_value(0.0) {} 
    ~FloatData() {}  
    /**
     *@brief 返回数据类型
     *@return  Datatype  
     *@retval  数据类型 
     **/
    Datatype data_type() {
        return FLOAT;   
    }
    
    /**
     *@brief 打印成功解析的数据
     *@return  void
     *@retval
     **/
    void print_data() {
        printf("(float)%g ", _data_value); 
    }

    /**
     *@brief 存储解析成功的数据
     *@param [in/out] input_data   : float 
     *@return  void
     **/
    void set_data_value(float input_data) {
        _data_value = input_data;  
    }

    /**
     *@brief 解析小数类型数据   
     *@param [in/out] str   : const std::string  
     *@return  int 
     **/
    int data_parser(const std::string& str);   
private:
    float _data_value;        /**< 存储解析成功的数据 */         

};

/**
 *@brief 字符串类型
 **/
class StrData : public IData {
public:
    StrData() : _data_value("") {}
    ~StrData() {}
    /**
     *@brief 返回数据类型  
     *@return  Datatype 
     **/
    Datatype data_type() {
        return STRING;    
    } 

    /** 
     *@brief 打印解析成功的数据   
     *@return  void
     **/
    void print_data() {
        printf("(string)%s ", _data_value.c_str());
    }

    /**
     *@brief 存储解析成功的数据      
     *@param [in/out] input_data   : const std::string
     *@return  void
     **/
    void set_data_value(const std::string input_data) {
        _data_value = input_data;    
    }

    /**
     *@brief 解析字符串类型数据     
     *@param [in/out] str   : const std::string 
     *@return  int
     **/
    int data_parser(const std::string& str);  

private:
    std::string _data_value;          /**< 存储解析成功的数据 */   
};

/**
 *@brief 整数数组类型   
 **/
class IntArrayData : public IData {
public:
    IntArrayData() : _data_value(0, 0) {}   
    ~IntArrayData() {}
      
    /**
     *@brief 返回数据类型 
     *@return  Datatype 
     **/
    Datatype data_type() {
        return INT_ARRAY; 
    }

    void print_data() {
        printf("(int_array)");  
        for (size_t i = 0; i < _data_value.size(); ++i) {
            printf("%d ", _data_value[i]);
        }
    }

    void set_data_value(const std::vector<int> input_data) {
        _data_value = input_data;   
    }

    int data_parser(const std::string& str); 

private: 
    std::vector<int> _data_value;         /**< 存储解析成功的数据 */     
};

/**
 *@brief 小数数组类型    
 **/
class FloatArrayData : public IData {
public:
    FloatArrayData() : _data_value(0, 0.0) {}
    ~FloatArrayData() {}  

    Datatype data_type() {
        return FLOAT_ARRAY;   
    }

    void print_data() {
        printf("(float_array)");  
        for (size_t i = 0; i < _data_value.size(); ++i) {
            printf("%g ", _data_value[i]); 
        }
    }
    
    void set_data_value(const std::vector<float> input_data) {
        _data_value = input_data;
    }    

    int data_parser(const std::string& str);

private:
    std::vector<float> _data_value;       /**< 存储成功解析的数据 */  
};

/**
 *@brief 字符串数组类型    
 **/
class StrArrayData : public IData {
public:
    StrArrayData() : _data_value(0, "") {}  
    ~StrArrayData() {} 
    
    Datatype data_type() {
        return STRING_ARRAY;  
    }

    void print_data() {
        printf("(str_array)");   

        for (size_t i = 0; i < _data_value.size(); ++i) {
            printf("%s ", _data_value[i].c_str());
        }
    }

    void set_data_value(const std::vector<std::string> input_data) {
        _data_value = input_data;   
    }

    int data_parser(const std::string& str);      

private:
    std::vector<std::string> _data_value;         /**< 存储成功解析的数据 */    
};

}
}

#endif
