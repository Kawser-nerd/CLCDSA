#include <iostream>
#include <stdint.h>

int main(void)
{
    int n;
    std::cin >> n;

    int x = 0;
    while (true)
    {
        int y = x + 1;
        if (y * y <= n)
        {
            x = y;
        }
        else
        {
            break;
        }
    }
    std::cout << (x * x) << std::endl;
    return 0;
}