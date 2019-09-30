#include <iostream>

int main(void)
{
    std::string a, b;
    std::cin >> a >> b;
    bool flag =
        (a[0] == b[2]) &&
        (a[1] == b[1]) &&
        (a[2] == b[0]);
    std::cout << (flag ? "YES" : "NO") << std::endl;
    return 0;
}