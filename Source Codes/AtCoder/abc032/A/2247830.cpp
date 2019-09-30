#include <iostream>

int main(void)
{
    int a, b, n;
    std::cin >> a >> b >> n;
    while (true)
    {
        if ((n % a == 0) && (n % b == 0))
        {
            std::cout << n << std::endl;
            return 0;
        }
        ++n;
    }
}