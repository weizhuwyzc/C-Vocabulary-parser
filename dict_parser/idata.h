#ifndef GOODCODER_WANGWEIZHU_IDATA_H
#define GOODCODER_WANGWEIZHU_IDATA_H

#include "data_type.h" 
#include <string>   

namespace wangweizhu {
namespace dict_parser {

class IData {
public:       
    
    virtual ~IData() {} 
    virtual Datatype data_type() = 0;      
    virtual void print_data() = 0;  
    virtual int data_parser(const std::string& str) = 0;  
};

}

}

#endif
