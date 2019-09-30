#include <iostream>

int main(void)
{
    int a, b;
    std::cin >> a >> b;
    bool flag = (a >= b);
    std::cout << (flag ? "Worse" : "Better") << std::endl;
    return 0;
}