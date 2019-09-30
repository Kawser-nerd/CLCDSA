#include <iostream>

int main(void)
{
    char a, b;
    std::cin >> a >> b;
    bool flag = (a == b);
    std::cout << (flag ? "H" : "D") << std::endl;
    return 0;
}