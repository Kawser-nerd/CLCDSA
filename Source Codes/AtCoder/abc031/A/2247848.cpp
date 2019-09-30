#include <iostream>

int main(void)
{
    int a, d;
    std::cin >> a >> d;
    int ret = (a < d) ? ((a + 1) * d) : (a * (d + 1));
    std::cout << ret << std::endl;
    return 0;
}