#include <iostream>

int main(void)
{
    int a, b, c;
    std::cin >> a >> b >> c;
    bool is_plus = (a + b) == c;
    bool is_minus = (a - b) == c;

    char output;
    if (is_plus && is_minus)
    {
        output = '?';
    }
    else if (is_plus)
    {
        output = '+';
    }
    else if (is_minus)
    {
        output = '-';
    }
    else
    {
        output = '!';
    }
    std::cout << output << std::endl;
    return 0;
}