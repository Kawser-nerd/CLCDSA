#include <iostream>
#include <stdint.h>

int main(void)
{
    int n, k;
    std::cin >> n >> k;

    int minval = std::numeric_limits<int>::max();
    for (int a = 0; a <= n; ++a)
    {
        int val = 1;
        for (int i = 0; i < n; ++i)
        {
            if (i < a)
            {
                val *= 2;
            }
            else
            {
                val += k;
            }
        }
        minval = std::min<int>(minval, val);
    }
    std::cout << minval << std::endl;
    return 0;
}