#include <iostream>

int main(){
    std::string str;
    std::cin >> str;

    str.at(3) = '8';

    std::cout << str << std::endl;

    return 0;
}