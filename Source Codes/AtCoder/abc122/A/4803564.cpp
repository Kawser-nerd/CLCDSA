#include <iostream>

int main() {
    char b;
    std::cin >> b;
    if(b == 'A') std::cout << 'T' << std::endl;
    if(b == 'T') std::cout << 'A' << std::endl;
    if(b == 'C') std::cout << 'G' << std::endl;
    if(b == 'G') std::cout << 'C' << std::endl;

    return 0;
}