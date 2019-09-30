#include <iostream>

int main(void)
{
    int a, b;
    std::cin >> a >> b;
    int box = b / a;
    if ((b % a) != 0) { ++box; }
    std::cout << box << std::endl;
    return 0;
}