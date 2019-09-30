#include <algorithm>
#include <iostream>

int main(void)
{
    int a, b;
    std::cin >> a >> b;
    int frac = a % b;
    std::cout << ((frac == 0) ? 0 : (b - frac)) << std::endl;
    return 0;
}