#include <iostream>

int main(void)
{
    int h, w;
    std::cin >> h >> w;
    for (int i = 0; i < w + 2; ++i)
    {
        std::cout << '#';
    }
    std::cout << std::endl;
    for (int i = 0; i < h; ++i)
    {
        std::string s;
        std::cin >> s;
        std::cout << '#' << s << '#' << std::endl;
    }
    for (int i = 0; i < w + 2; ++i)
    {
        std::cout << '#';
    }
    std::cout << std::endl;
    return 0;
}