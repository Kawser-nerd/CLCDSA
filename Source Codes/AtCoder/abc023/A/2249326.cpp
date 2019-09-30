#include <iostream>

int main(void)
{
    int x;
    std::cin >> x;
    std::cout << ((x / 10) + (x % 10)) << std::endl;
    return 0;
}