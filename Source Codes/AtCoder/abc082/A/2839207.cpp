#include <iostream>

int main() {
    double x, y;
    std::cin >> x >> y;
    double z = (x + y) / 2;
    if (z - (int)z) z++;
    std::cout << (int)z << std::endl;
    return 0;
}