#include <iostream>

int main(void)
{
    int n, f = 0;
    std::cin >> n;
    {
        int m = n;
        while (0 < m)
        {
            f += m % 10;
            m /= 10;
        }
    }
    bool flag = (n % f) == 0;
    std::cout << (flag ? "Yes" : "No") << std::endl;
    return 0;
}