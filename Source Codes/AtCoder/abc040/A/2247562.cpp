#include <algorithm>
#include <iostream>

int main(void)
{
    int n, x;
    std::cin >> n >> x;
    std::cout << std::min<int>(x - 1, n - x) << std::endl;
    return 0;
}