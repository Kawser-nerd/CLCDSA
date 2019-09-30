#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;
    const char* ans[] = { "ABC", "chokudai" };
    std::cout << ans[n - 1] << std::endl;
    return 0;
}