#include <iostream>

int main(){
    int a, b;
    std::cin >> a >> b;

    std::cout << a*b - (a + b - 1) << std::endl;

    return 0;
}