#include <iostream>

int main(void)
{
    int a;
    std::cin >> a;
    bool flag = (a >= 90) || (a % 10 == 9);
    std::cout << (flag ? "Yes" : "No") << std::endl;
    return 0;
}