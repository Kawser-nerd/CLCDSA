#include <algorithm>
#include <iostream>

int main(void)
{
    int total = 0;
    for (int i = 0; i < 3; ++i)
    {
        int s, e;
        std::cin >> s >> e;
        total += s * e / 10;
    }
    std::cout << total << std::endl;
    return 0;
}