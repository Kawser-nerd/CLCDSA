#include <iostream>
#include <string>

int main(void)
{
    std::string s;
    std::cin >> s;
    std::cout << s[0] << (s.size() - 2) << s[s.size() - 1] << std::endl;
    return 0;
}