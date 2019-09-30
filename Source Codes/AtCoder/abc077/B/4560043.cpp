#include <iostream>
#include <cmath>

int main(){
    long n;
    std::cin >> n;

    long i = 0;
    while((long)std::pow(i, 2) <= n){
        ++i;
    }

    std::cout << (long)std::pow(i - 1, 2) << std::endl;

    return 0;
}