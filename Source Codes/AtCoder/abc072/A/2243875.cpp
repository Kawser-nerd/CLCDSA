#include <iostream>

int main(void)
{
    int x, t;
    std::cin >> x >> t;
    x = std::max<int>(0, x - t);
    std::cout << x << std::endl;
    return 0;
}