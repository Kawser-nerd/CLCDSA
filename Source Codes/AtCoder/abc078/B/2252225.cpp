#include <iostream>
#include <stdint.h>

int main(void)
{
    int x, y, z;
    std::cin >> x >> y >> z;
    std::cout << ((x - z) / (y + z)) << std::endl;
    return 0;
}