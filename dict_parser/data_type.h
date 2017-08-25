#ifndef GOODCODER_WANGWEIZHU_DATA_TYPE_H
#define GOODCODER_WANGWEIZHU_DATA_TYPE_H

namespace wangweizhu {
namespace dict_parser {

enum Datatype {
    INT,                  /**< 整数类型       */      
    FLOAT,                /**< 小数类型       */   
    STRING,               /**< 字符串类型       */   
    INT_ARRAY,            /**< 整数数组类型       */   
    FLOAT_ARRAY,          /**< 小数数组类型       */        
    STRING_ARRAY,         /**< 字符串数组类型       */     
    USER_TYPE,            /**< 用户自定义数据类型       */      
    DATA_TYPE_NUM         /**< 所有可以解析的数据类型的数量  */       
};

}

}

#endif
