#include <iostream>
#include <vector>
#include <algorithm> 

int gcd(int a, int b) {
    if (a > b) {
        return gcd(b, a);
    } else {
        if (b % a == 0) {
            return a;
        } else {
            return gcd(b % a, a);
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) 
        std::cin >> a[i];
    int ans = a[0];
    for (int i = 1; i < n; i++) {
        ans = gcd(ans, a[i]);
    }
    std::cout << ans << std::endl;
}