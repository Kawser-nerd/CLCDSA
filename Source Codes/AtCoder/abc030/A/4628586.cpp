#include <iostream>

int main(){
    float a, b, c, d;
    std::cin >> a >> b >> c >> d;

    if(b / a < d / c){
        std::cout << "AOKI" << std::endl;
    }else if(b / a > d / c){
        std::cout << "TAKAHASHI" << std::endl;
    }else{
        std::cout << "DRAW" << std::endl;
    }

    return 0;
}