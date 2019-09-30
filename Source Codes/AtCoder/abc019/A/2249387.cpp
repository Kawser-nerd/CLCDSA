#include <algorithm>
#include <iostream>

int main(void)
{
    int a[3];
    std::cin >> a[0] >> a[1] >> a[2];
    std::sort(std::begin(a), std::end(a));
    std::cout << a[1] << std::endl;
    return 0;
}