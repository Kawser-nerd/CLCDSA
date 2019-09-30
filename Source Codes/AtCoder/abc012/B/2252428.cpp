#include <iostream>
#include <string>

int main(void)
{
    int n;
    std::cin >> n;
    int h = n / 3600;
    int m = (n / 60) % 60;
    int s = n % 60;

    char buf[256];
    snprintf(buf, 256, "%02d:%02d:%02d", h, m, s);
    std::cout << buf << std::endl;
    return 0;
}