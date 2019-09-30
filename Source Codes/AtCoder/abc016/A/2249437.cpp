#include <algorithm>
#include <iostream>

int main(void)
{
    int m, d;
    std::cin >> m >> d;
    bool flag = (m % d) == 0;
    std::cout << (flag ? "YES" : "NO") << std::endl;
    return 0;
}