#include <iostream>

int main(){
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    if(a*b < c*d){
        std::cout << c*d << std::endl;
    }else{
        std::cout << a*b << std::endl;
    }

    return 0;
}