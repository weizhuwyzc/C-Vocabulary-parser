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
     *@brief ������������  
     *@return  Datatype
     *@retval  ��������
     **/
    Datatype data_type() {
        return USER_TYPE;
    }

    /**
     *@brief ��ӡ�����ɹ�������   
     *@return  void
     **/
    void print_data() {
        printf("(name)%s, (age)%d, (K/D/A)%g/%g/%g ",    
                _name.c_str(), _age, _kill, _dead, _assist); 
    }

    /** 
     *@brief �����û��Զ������������    
     *@param [in/out] str   : const std::string  
     *@return  int  
     **/
    int data_parser(const std::string& str); 
        
    /** 
     *@brief ���ش洢�����ݳ�Ա����   
     *@return  int   
     **/
    int get_member_cnt() {
        return _member_cnt;
    }

private:
    std::string _name;        /**< ������� */ 
    int _age;             /**< �������       */   
    float _kill;          /**< ������ɱ       */   
    float _dead;          /**< ��������       */    
    float _assist;        /**< ��������       */       
    std::string _str_separator;       /**< �ַ����ָ���  */     
    int _member_cnt;          /**< �洢�����ݳ�Ա����   */    
};
}
}

#endif 
