#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    long long int k;
    std::cin >> n >> k;
    std::vector<std::pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        v[i] = {a, b};
    }
    std::sort(v.begin(), v.end());
    for (auto x : v) {
        k -= x.second;
        if (k <= 0) {
            std::cout << x.first << std::endl;
            break;
        }
    }
}