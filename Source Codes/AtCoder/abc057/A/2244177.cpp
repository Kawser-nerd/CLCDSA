#include <iostream>

int main(void)
{
    int a, b;
    std::cin >> a >> b;
    std::cout << ((a + b) % 24) << std::endl;
    return 0;
}