#include <iostream>

int main(void)
{
    int w, h;
    std::cin >> w >> h;
    bool flag = (w * 3 == h * 4);
    std::cout << (flag ? "4:3" : "16:9") << std::endl;
    return 0;
}