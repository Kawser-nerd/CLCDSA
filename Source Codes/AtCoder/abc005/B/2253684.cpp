#include <iostream>
#include <limits>

int main(void)
{
    int n;
    std::cin >> n;

    int s = std::numeric_limits<int>::max();
    for (int i = 0; i < n; ++i)
    {
        int a;
        std::cin >> a;
        s = std::min<int>(s, a);
    }
    std::cout << s << std::endl;
    return 0;
}