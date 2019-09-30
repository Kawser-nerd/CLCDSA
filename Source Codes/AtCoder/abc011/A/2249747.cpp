#include <algorithm>
#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;
    std::cout << ((n % 12) + 1) << std::endl;
    return 0;
}