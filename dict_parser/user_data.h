#ifndef GOODCODER_WANGWEIZHU_USER_DATA_H
#define GOODCODER_WANGWEIZHU_USER_DATA_H

#include "idata.h"
#include <string>

namespace wangweizhu {
namespace dict_parser {

class UserData : public IData {
public:     
    UserData() : _name(""), _age(0), _kill(0.0),    
        _dead(0.0), _assist(0.0),
        _str_separator(":"), _member_cnt(5) {} 
    ~UserData() {} 
    /**
     *@brief 返回数据类型  
     *@return  Datatype
     *@retval  数据类型
     **/
    Datatype data_type() {
        return USER_TYPE;
    }

    /**
     *@brief 打印解析成功的数据   
     *@return  void
     **/
    void print_data() {
        printf("(name)%s, (age)%d, (K/D/A)%g/%g/%g ",    
                _name.c_str(), _age, _kill, _dead, _assist); 
    }

    /** 
     *@brief 解析用户自定义的数据类型    
     *@param [in/out] str   : const std::string  
     *@return  int  
     **/
    int data_parser(const std::string& str); 
        
    /** 
     *@brief 返回存储的数据成员个数   
     *@return  int   
     **/
    int get_member_cnt() {
        return _member_cnt;
    }

private:
    std::string _name;        /**< 玩家名字 */ 
    int _age;             /**< 玩家年龄       */   
    float _kill;          /**< 场均击杀       */   
    float _dead;          /**< 场均死亡       */    
    float _assist;        /**< 场均助攻       */       
    std::string _str_separator;       /**< 字符串分隔符  */     
    int _member_cnt;          /**< 存储的数据成员个数   */    
};
}
}

#endif 
