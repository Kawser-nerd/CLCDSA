#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<long long int, int>> inp(n);
    for (int i = 0; i < n; i++) {
        std::cin >> inp[i].first >> inp[i].second;
    }
    std::sort(inp.begin(), inp.end());
    long long int ans = 0;
    for (auto x : inp) {
        if (m < x.second) {
            ans += x.first * m;
            break;
        } else {
            ans += x.first * x.second;
            m -= x.second;
        }
    }
    std::cout << ans << std::endl;
}