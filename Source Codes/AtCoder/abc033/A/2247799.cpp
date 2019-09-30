#include <iostream>

int main(void)
{
    std::string n;
    std::cin >> n;
    bool flag = (n[0] == n[1]) && (n[0] == n[2]) && (n[0] == n[3]);
    std::cout << (flag ? "SAME" : "DIFFERENT") << std::endl;
    return 0;
}