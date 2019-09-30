#include <iostream>
#include <unordered_map>

int main()
{
    int m, n;
    int a[100000];

    std::cin >> n >> m;

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    uint64_t b[100001];
    b[0] = 0;
    for (int i = 1; i <= n; i++) {
        b[i] = b[i - 1] + a[i - 1];
    }

    std::unordered_map<int, uint64_t> map;
    for (int i = 1; i <= n; i++) {
        int mod = b[i] % m;
        map[mod] += 1;
    }

    uint64_t count_sum = 0;
    for (auto& e : map) {
        count_sum += (e.second * (e.second - 1)) / 2;
    }
    if (map.count(0) != 0) {
        count_sum += map[0];
    }

    std::cout << count_sum << std::endl;

    return 0;
}