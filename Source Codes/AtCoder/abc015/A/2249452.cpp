#include <algorithm>
#include <iostream>

int main(void)
{
    std::string a, b;
    std::cin >> a >> b;
    bool flag = a.length() > b.length();
    std::cout << (flag ? a : b) << std::endl;
    return 0;
}