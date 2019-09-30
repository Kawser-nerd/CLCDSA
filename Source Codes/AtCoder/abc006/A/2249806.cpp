#include <algorithm>
#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;
    bool flag = (n % 3) == 0;
    std::cout << (flag ? "YES" : "NO") << std::endl;
    return 0;
}