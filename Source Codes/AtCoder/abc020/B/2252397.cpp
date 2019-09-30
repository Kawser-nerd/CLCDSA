#include <iostream>
#include <string>

int main(void)
{
    std::string a, b;
    std::cin >> a >> b;
    int n = std::stoi(a + b);
    std::cout << (n * 2) << std::endl;
    return 0;
}