#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;

    int total = 0;
    for (int i = 0; i < n; ++i)
    {
        int l, r;
        std::cin >> l >> r;
        total += r - l + 1;
    }
    std::cout << total << std::endl;
    return 0;
}