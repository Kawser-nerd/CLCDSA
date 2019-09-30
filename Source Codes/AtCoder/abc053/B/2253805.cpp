#include <iostream>

int main(void)
{
    std::string s;
    std::cin >> s;

    auto a = s.find("A");
    auto z = s.rfind("Z");
    std::cout << (z + 1 - a) << std::endl;
    return 0;
}