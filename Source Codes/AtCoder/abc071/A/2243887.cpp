#include <iostream>

int main(void)
{
    int x, a, b;
    std::cin >> x >> a >> b;
    bool flag = abs(x - a) < abs(x - b);
    std::cout << (flag ? "A" : "B") << std::endl;
    return 0;
}