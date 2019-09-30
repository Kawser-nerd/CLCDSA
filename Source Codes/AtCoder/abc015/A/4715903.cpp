#include <iostream>

int main(){
    std::string a, b;
    std::cin >> a >> b;

    if(a.size() < b.size()){
        std::cout << b << std::endl;
    }else{
        std::cout << a << std::endl;
    }

    return 0;
}