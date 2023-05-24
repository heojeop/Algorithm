#include <iostream>
#include <string> 
#include <functional>

int main(void){

    std::string str = "Hello, World !";
    
    std::hash<std::string> str_hash;

    std::cout << "Hash of" << str << " is : " << str_hash(str) << std::endl;

    int num = 42;
    std::hash<int> int_hash;

    std::cout << "Hash of" << num << " is : " << int_hash(num) << std::endl;

    return 0;
}