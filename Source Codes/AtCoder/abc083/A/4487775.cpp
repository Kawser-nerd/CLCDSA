#include <iostream>

int main(){
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    if(a + b > c + d){
        std::cout << "Left" << std::endl;
    }else if(a + b < c + d){
        std::cout << "Right" << std::endl;
    }else{
        std::cout << "Balanced" << std::endl;
    }

    return 0;
}