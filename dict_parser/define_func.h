#ifndef GOODCODER_WANGWEIZHU_DEFINE_FUNC_H 
#define GOODCODER_WANGWEIZHU_DEFINE_FUNC_H 

#include <string>  
#include "ul_log.h"  

namespace wangweizhu {
namespace dict_parser {

#define    WARNING(format, args...) \
    ul_writelog(UL_LOG_WARNING, "[%s:%d] "format, __FILE__, __LINE__, ##args)   

#define    FATAL(format, args...) \   
    ul_writelog(UL_LOG_FATAL, "[%s:%d] "format, __FILE__, __LINE__, ##args)     

}
}

#endif
