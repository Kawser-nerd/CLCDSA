#include <iostream>

int main(void)
{
    int a, b, c, k, s, t;
    std::cin >> a >> b >> c >> k >> s >> t;
    int total = a * s + b * t;
    int number = s + t;
    if (number >= k)
    {
        total -= number * c;
    }
    std::cout << total << std::endl;
    return 0;
}