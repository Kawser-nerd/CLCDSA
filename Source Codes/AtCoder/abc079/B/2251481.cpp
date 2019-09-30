#include <iostream>
#include <stdint.h>

int main(void)
{
    int n;
    std::cin >> n;

    int64_t l[100];
    l[0] = 2;
    l[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        l[i] = l[i - 2] + l[i - 1];
    }
    std::cout << l[n] << std::endl;
    return 0;
}