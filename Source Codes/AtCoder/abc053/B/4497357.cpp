#include <iostream>
#include <string>

int main(){
    std::string str;
    std::cin >> str;

    std::cout << str.rfind('Z') - str.find('A') + 1 << std::endl;    

    return 0;
}