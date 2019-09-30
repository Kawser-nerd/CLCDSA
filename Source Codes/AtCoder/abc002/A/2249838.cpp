#include <algorithm>
#include <iostream>

int main(void)
{
    int x, y;
    std::cin >> x >> y;
    std::cout << std::max<int>(x, y) << std::endl;
    return 0;
}