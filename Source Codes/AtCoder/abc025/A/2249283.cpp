#include <iostream>

int main(void)
{
    std::string s;
    int n;
    std::cin >> s >> n;
    --n;
    std::cout << s[n / 5] << s[n % 5] << std::endl;
    return 0;
}