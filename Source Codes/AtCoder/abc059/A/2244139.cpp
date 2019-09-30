#include <iostream>

int main(void)
{
    std::string a, b, c;
    std::cin >> a >> b >> c;
    char x = a[0], y = b[0], z = c[0];
    x -= 0x20;
    y -= 0x20;
    z -= 0x20;
    std::cout << x << y << z << std::endl;
    return 0;
}