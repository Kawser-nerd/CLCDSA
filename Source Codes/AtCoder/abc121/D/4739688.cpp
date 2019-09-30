#include <iostream>
#include <vector>

long long int num_of_one(long long int x, long long int digit) {
    long long int n = 1L << (digit + 1L);
    long long int ret = (x / n) * (n / 2LL) + std::max(x % n - n / 2LL + 1LL, 0LL);
    return ret;
}

int main() {
    long long int a, b;
    std::cin >> a >> b;
    long long int bb = b;
    int digits = 0;
    while (bb > 0) {
        digits++;
        bb = bb >> 1;
    }
    long long int ans = 0;
    for (int i = 0; i < digits; i++) {
        long long int ones_b = num_of_one(b, digits-i-1);
        long long int ones_a = num_of_one(std::max(0LL, a-1), digits-i-1);
        long long int ones = ones_b - ones_a;
        ans += ones % 2;
        if (i != digits - 1) ans = ans << 1;
    }
    std::cout << ans << std::endl;
}