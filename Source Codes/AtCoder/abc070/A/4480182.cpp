#include <iostream>
#include <algorithm>

int main(){
    std::string str;
    std::cin >> str;

    std::string rev = str;
    std::reverse(str.begin(), str.end());
    if(str == rev){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }

    return 0;
}