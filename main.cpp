
#include "dict_parser.h"
#include <sstream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s data_file.conf\n", argv[0]);
        return 0;
    }

    std::string file_name = "";  
    std::stringstream ss;    
    ss << argv[1];  
    ss >> file_name;   

    wangweizhu::dict_parser::DictParser dict_parser;  

    int ret = dict_parser.read_file_by_line(file_name);    

    return ret;
}
