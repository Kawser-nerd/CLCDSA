#include <iostream>
#include <vector>
#include <cmath>

using ll = long long int;

int main() {
    ll n;    
    std::cin >> n;
    int ans = 10000000;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans = std::min(ans, std::max((int)std::log10(i), (int)std::log10(n / i) + 1));
        }
    }
    std::cout << ans << std::endl;
}