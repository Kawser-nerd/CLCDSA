#include <iostream>

int main(void)
{
    int a, b, c;
    std::cin >> a >> b >> c;
    bool flag = (a <= c) && (c <= b);
    std::cout << (flag ? "Yes" : "No") << std::endl;
    return 0;
}