#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        std::cin >> tmp;
        ans += tmp;
    }
    std::cout << ans - n << std::endl;
}