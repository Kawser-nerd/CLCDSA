#include <iostream>

int main(void)
{
    int a, b, c;
    std::cin >> a >> b >> c;
    bool flag = ((a + b) == c) || ((a + c) == b) || ((b + c) == a);
    std::cout << (flag ? "Yes" : "No") << std::endl;
    return 0;
}