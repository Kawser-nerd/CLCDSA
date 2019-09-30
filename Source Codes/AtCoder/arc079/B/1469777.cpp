#include <cstdio>
#include <iostream>
#include <algorithm>

using LL = long long;

void eval(LL arr[50]) {
    auto it = std::min_element(arr, arr + 50) - arr;
    arr[it] += 50;
    for (int i = 0; i < 50; ++i) {
        if (i != it)
            --arr[i];
    }
}

bool solve() {
    LL k;
    std::cin >> k;
    if (k == 0) {
        std::cout << "2\n1 1";
    } else if (k == 1) {
        std::cout << "2\n2 0";
    } else if (k <= 50) {
        std::cout << k << '\n';
        for (LL i = 0; i < k; ++i)
            std::cout << i + 1 << ' ';
    } else {
        LL p = 50;
        std::cout << p << '\n';
        LL n = k / p + p - 1; 
        LL s = k % p;
        LL arr[50];
        for (LL i = 0; i < p; ++i)
            arr[i] = n - i;
        for (LL i = 0; i < s; ++i)
            eval(arr);
        for (int i = 0; i < p; ++i)
            std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}

int main() {
#ifdef LOCALHOST
    freopen("input", "r", stdin);
#endif
    while (solve());

    return 0;
}