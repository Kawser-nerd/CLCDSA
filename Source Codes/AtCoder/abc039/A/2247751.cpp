#include <iostream>

int main(void)
{
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << ((a * b) + (b * c) + (c * a)) * 2 << std::endl;
    return 0;
}