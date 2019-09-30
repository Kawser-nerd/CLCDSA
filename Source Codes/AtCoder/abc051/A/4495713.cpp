#include <iostream>

int main(){
    std::string str;
    std::cin >> str;
    for(int i = 0; i <= str.length(); i ++) if (str[i] == ',') str[i] = ' ';
    std::cout << str;
}