#include <iostream>

int main(){
    int x, a, b;
    std::cin >> x >> a >> b;

    std::cout << x - (a + b*((x - a)/b)) << std::endl;

    return 0;
}