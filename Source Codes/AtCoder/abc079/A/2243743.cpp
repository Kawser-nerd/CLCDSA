#include <iostream>

int main(void)
{
    int input, a, b, c, d;
    std::cin >> input;
    a = input / 1000;
    b = (input / 100) % 10;
    c = (input / 10) % 10;
    d = input % 10;
    bool good = (b == c) && ((a == b) || (c == d));
    std::cout << (good ? "Yes" : "No") << std::endl;
    return 0;
}