#include <iostream>

int main(void)
{
    std::string text;
    std::cin >> text;
    text[3] = '8';
    std::cout << text << std::endl;
    return 0;
}