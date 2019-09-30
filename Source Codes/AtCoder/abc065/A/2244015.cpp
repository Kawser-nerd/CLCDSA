#include <iostream>

int main(void)
{
    int x, a, b;
    std::cin >> x >> a >> b;
    int left = a - b;
    if (left >= 0)
    {
        std::cout << "delicious";
    }
    else if (left >= -x)
    {
        std::cout << "safe";
    }
    else
    {
        std::cout << "dangerous";
    }
    std::cout << std::endl;
    return 0;
}