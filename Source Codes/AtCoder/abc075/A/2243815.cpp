#include <iostream>

int main(void)
{
    int a, b, c;
    std::cin >> a >> b >> c;
    int r;
    if (a == b)
    {
        r = c;
    }
    else if (a == c)
    {
        r = b;
    }
    else
    {
        r = a;
    }
    std::cout << r << std::endl;
    return 0;
}