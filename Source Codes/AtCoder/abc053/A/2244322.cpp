#include <iostream>

int main(void)
{
    int x;
    std::cin >> x;
    std::cout << (x < 1200 ? "ABC" : "ARC") << std::endl;
    return 0;
}