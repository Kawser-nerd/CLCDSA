#include <iostream>

int main(void)
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    bool left = (a + b) > (c + d);
    bool right = (a + b) < (c + d);
    std::string ret = left ? "Left" : right ? "Right" : "Balanced";
    std::cout << ret << std::endl;
    return 0;
}