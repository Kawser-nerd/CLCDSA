#include <iostream>

int main(void)
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    if (b * c > a * d)
    {
        std::cout << "TAKAHASHI";
    }
    else if (b * c < a * d)
    {
        std::cout << "AOKI";
    }
    else
    {
        std::cout << "DRAW";
    }
    std::cout << std::endl;
    return 0;
}