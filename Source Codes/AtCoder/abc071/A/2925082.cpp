#include <iostream>
#include <cstdlib>

int main()
{
    int x, a, b; std::cin >> x >> a >> b;
    std::cout << (abs(x - a) < abs(x - b) ? 'A' : 'B') << std::endl;
    return 0;
}