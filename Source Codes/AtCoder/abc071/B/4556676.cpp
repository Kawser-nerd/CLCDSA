#include <iostream>
#include <algorithm>

int main(){
    std::string s;
    std::cin >> s;

    int i;
    for(i = 97; i < 124; ++i){
        if(std::string::npos == s.find((char)i)){
            break;
        }
    }

    if(123 == i){
        std::cout << "None" << std::endl;
    }else{
        std::cout << (char)i << std::endl;
    }

    return 0;
}