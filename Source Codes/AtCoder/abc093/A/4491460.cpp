#include <iostream>
#include <algorithm>

int main(){
    std::string str;
    std::cin >> str;

    std::sort(str.begin(), str.end());
    if("abc" == str){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }

    return 0;
}