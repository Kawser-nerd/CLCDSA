#include <iostream>

int main(void)
{
    int a, b, c, d;
    std::cin >> a >> b >> c;
    if (a == b)
    {
        d = c;
    }
    else if (a == c)
    {
        d = b;
    }
    else
    {
        d = a;
    }
    std::cout << d << std::endl;
    return 0;
}