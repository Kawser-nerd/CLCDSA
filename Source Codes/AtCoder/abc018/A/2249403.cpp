#include <algorithm>
#include <iostream>

int main(void)
{
    int a[3];
    std::cin >> a[0] >> a[1] >> a[2];
    int win = std::max<int>(std::max<int>(a[0], a[1]), a[2]);
    int lose = std::min<int>(std::min<int>(a[0], a[1]), a[2]);
    for (int i = 0; i < 3; ++i)
    {
        if (a[i] == win)
        {
            std::cout << 1 << std::endl;
        }
        else if (a[i] == lose)
        {
            std::cout << 3 << std::endl;
        }
        else
        {
            std::cout << 2 << std::endl;
        }
    }
    return 0;
}