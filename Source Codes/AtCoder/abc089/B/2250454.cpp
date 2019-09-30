#include <algorithm>
#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;
    bool four = false;
    for (int i = 0; i < n; ++i)
    {
        char c;
        std::cin >> c;
        if (c == 'Y')
        {
            four = true;
        }
    }
    std::cout << (four ? "Four" : "Three") << std::endl;
}