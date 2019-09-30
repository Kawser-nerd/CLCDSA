#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;

    int m = 1;
    while (m * 2 <= n)
    {
        m *= 2;
    }
    std::cout << m << std::endl;
    return 0;
}