#include <iostream>

int main(){
    int a, b;
    std::cin >> a >> b;

    int c = a + b;
    if(c > 23){
        std::cout << c - 24 << std::endl;
    }else{
        std::cout << c << std::endl;
    }

    return 0;
}