#include <algorithm>
#include <iostream>

int main(void)
{
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << (c / std::min<int>(a, b)) << std::endl;
    return 0;
}