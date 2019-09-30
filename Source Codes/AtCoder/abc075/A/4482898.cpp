#include <iostream>

int main(){
    int a, b, c;
    std::cin >> a >> b >> c;

    if(a == b){
        std::cout << c << std::endl;
    }else if(b == c){
        std::cout << a << std::endl;
    }else if(c == a){
        std::cout << b << std::endl;
    }

    return 0;
}