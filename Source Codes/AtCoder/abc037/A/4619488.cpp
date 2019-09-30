#include <iostream>

int main(){
    int a, b, c;
    std::cin >> a >> b >> c;

    if(a < b){
        std::cout << c / a << std::endl;
    }else{
        std::cout << c / b << std::endl;
    }

    return 0;
}