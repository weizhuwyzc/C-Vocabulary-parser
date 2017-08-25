#include <gtest/gtest.h>  
#include "buildin_data.h" 
#include "idata.h" 

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);    
    return RUN_ALL_TESTS(); 
}

class TestIntDataSuite : public ::testing::Test {
protected: 
    TestIntDataSuite() {};
    virtual ~TestIntDataSuite() {};   
    virtual void SetUp() {
         
    };
    virtual void TearDown() {
           
    };
    
};

TEST_F(TestIntDataSuite, int_when_success_ret_0) {
    wangweizhu::dict_parser::IntData int_data; 
    int ret = int_data.data_parser("9536847"); 
    ASSERT_EQ(0, ret); 
}

TEST_F(TestIntDataSuite, int_when_fail_ret_negative_1) {
    wangweizhu::dict_parser::IntData int_data;  
    int ret = int_data.data_parser("96368Qq");     
    ASSERT_EQ(-1, ret); 
}

TEST_F(TestIntDataSuite, float_when_success_ret_0) {
    wangweizhu::dict_parser::FloatData float_data; 
    int ret = float_data.data_parser("953.1");   
    ASSERT_EQ(0, ret);  
}

TEST_F(TestIntDataSuite, float_when_fail_ret_negative_1) {
    wangweizhu::dict_parser::FloatData float_data;     
    int ret = float_data.data_parser("368Qq");
    ASSERT_EQ(-1, ret);
}

TEST_F(TestIntDataSuite, str_when_success_ret_0) {
    wangweizhu::dict_parser::StrData str_data; 
    int ret = str_data.data_parser("good_coder");  
    ASSERT_EQ(0, ret);  
}

class TestIntArrayDataSuite : public ::testing::Test {
protected:
    TestIntArrayDataSuite() {};
    virtual ~TestIntArrayDataSuite() {};   
    virtual void SetUp() {
          
    };
    virtual void TearDown() {
          
    };

};

TEST_F(TestIntArrayDataSuite, int_array_when_success_ret_0) {
    wangweizhu::dict_parser::IntArrayData int_array_data;  
    int ret = int_array_data.data_parser("5:9,5,3,6,8"); 
    ASSERT_EQ(0, ret);   
}

TEST_F(TestIntArrayDataSuite, int_array_when_fail_ret_negative_1) {
    wangweizhu::dict_parser::IntArrayData int_array_data; 
    int ret = int_array_data.data_parser("5:qQ,5,3,6,8");  
    ASSERT_EQ(-1, ret); 
}

TEST_F(TestIntArrayDataSuite, float_array_when_success_ret_0) {
    wangweizhu::dict_parser::FloatArrayData  float_array_data;
    int ret = float_array_data.data_parser("3:9.1,5.2,3.3");  
    ASSERT_EQ(0, ret);  
}

TEST_F(TestIntArrayDataSuite, float_array_when_fail_ret_negative_1) {
    wangweizhu::dict_parser::FloatArrayData  float_array_data; 
    int ret = float_array_data.data_parser("2:1.1,q4r");  
    ASSERT_EQ(-1, ret); 
}

TEST_F(TestIntArrayDataSuite, str_array_when_success_ret_0) {
    wangweizhu::dict_parser::StrArrayData  str_array_data;  
    int ret = str_array_data.data_parser("3:ab,cd,ef");     
    ASSERT_EQ(0, ret);    
}

