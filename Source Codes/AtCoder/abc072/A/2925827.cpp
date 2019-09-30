#include <iostream>

int main()
{
    int x, t; std::cin >> x >> t;
    std::cout << (x - t >= 0 ? x - t : 0) << std::endl;
    return 0;
}