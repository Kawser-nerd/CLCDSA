#include <iostream>

int main(void)
{
    int h1, w1, h2, w2;
    std::cin >> h1 >> w1 >> h2 >> w2;
    bool flag = (h1 == h2) || (h1 == w2) ||
                (w1 == h2) || (w1 == w2);
    std::cout << (flag ? "YES" : "NO") << std::endl;
    return 0;
}