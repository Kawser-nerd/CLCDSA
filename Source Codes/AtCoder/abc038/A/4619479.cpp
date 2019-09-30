#include <iostream>

int main(){
    std::string s;
    std::cin >> s;

    if('T' == *(s.end() - 1)){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }

    return 0;
}