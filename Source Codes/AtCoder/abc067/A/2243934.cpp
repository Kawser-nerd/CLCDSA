#include <iostream>

int main(void)
{
    int a, b;
    std::cin >> a >> b;
    bool flag = (a % 3 == 0) || (b % 3 == 0) ||
    ((a + b) % 3 == 0);
    std::cout << (flag ? "Possible" : "Impossible") << std::endl;
    return 0;
}