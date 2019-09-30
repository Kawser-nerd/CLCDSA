#include <iostream>

int main(){
    int x, y;
    std::cin >> x >> y;

    if(x < y){
        std::cout << y << std::endl;
    }else{
        std::cout << x << std::endl;
    }

    return 0;
}