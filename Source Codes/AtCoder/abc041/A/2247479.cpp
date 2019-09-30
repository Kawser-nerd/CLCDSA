#include <iostream>

int main(void)
{
    std::string s;
    int i;
    std::cin >> s >> i;
    std::cout << s[i - 1] << std::endl;
    return 0;
}