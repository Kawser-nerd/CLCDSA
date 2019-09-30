#include <iostream>

int main(void)
{
    std::string s;
    std::cin >> s;
    bool flag = (s.back() == 'T');
    std::cout << (flag ? "YES" : "NO") << std::endl;
    return 0;
}