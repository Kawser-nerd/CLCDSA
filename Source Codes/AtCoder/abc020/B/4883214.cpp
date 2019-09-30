#include <iostream>
#include <cmath>
#include <boost/lexical_cast.hpp>

int main(){
    int a, b;
    std::cin >> a >> b;

    int exp = log10(b) + 1;
    int ans = a * std::pow(10, exp) + b;
    std::cout << 2 * ans << std::endl;

    return 0;
}