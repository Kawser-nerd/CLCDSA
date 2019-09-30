#include <iostream>

int main(void)
{
    int a, b;
    std::cin >> a >> b;
    int total = a + b;
    if (total >= 10)
    {
        std::cout << "error";
    }
    else
    {
        std::cout << total;
    }
    std::cout << std::endl;
    return 0;
}