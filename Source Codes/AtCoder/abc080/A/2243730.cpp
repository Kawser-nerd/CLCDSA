#include <algorithm>
#include <iostream>

int main(void)
{
    int t, a, b;
    std::cin >> t >> a >> b;
    int cost = std::min<int>(t * a, b);
    std::cout << cost << std::endl;
    return 0;
}