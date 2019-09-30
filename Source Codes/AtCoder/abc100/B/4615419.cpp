#include <iostream>
#include <cmath>

int main(){
    long d, n;
    std::cin >> d >> n;

    if(n < 100){
        std::cout << (long)std::pow(100, d) * n << std::endl;
    }else{
        std::cout << (long)std::pow(100, d) * (n + 1) << std::endl;
    }

    return 0;
}