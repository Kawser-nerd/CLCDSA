#include <algorithm>
#include <iostream>

int main(void)
{
    int a, b, c;
    std::cin >> a >> b >> c;
    int m = std::max<int>(std::max<int>(a, b), c);
    std::cout << (a + b + c - m) << std::endl;
    return 0;
}