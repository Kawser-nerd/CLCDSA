#include <algorithm>
#include <iostream>

int main(void)
{
    char x;
    std::cin >> x;
    std::cout << (int(x - 'A') + 1) << std::endl;
    return 0;
}