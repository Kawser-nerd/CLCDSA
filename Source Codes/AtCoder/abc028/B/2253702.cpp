#include <iostream>

int main(void)
{
    std::string s;
    std::cin >> s;

    int count[6] = { 0 };
    for (int i = 0; i < int(s.length()); ++i)
    {
        ++count[s[i] - 'A'];
    }
    for (int i = 0; i < 6; ++i)
    {
        std::cout << count[i];
        if (i < 5)
        {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;
    return 0;
}