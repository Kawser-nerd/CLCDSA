#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
static const int mod = 998244353;

ll *fact, *inv;

ll C(int n, int r) {
    if (n < 0 || r < 0 || r > n) { return 0; }
    if (r > n / 2) { r = n - r; }
    return fact[n] * inv[r] % mod * inv[n-r] % mod;
}

ll extpow(ll x, ll y) {
    if (y == 0) { return 1; }
    else if (y == 1) { return x % mod; }
    else {
        ll part = extpow(x, y/2);
        if (y % 2 == 0) {
            return part * part % mod;
        } else { 
            return part * part % mod * x % mod;
        }
    }
}

int main() {
    int n, a, b;
    ll k;
    scanf("%d %d %d %lld", &n, &a, &b, &k);

    fact = new ll[n+1];
    inv = new ll[n+1];
    fact[0] = 1;

    for (int i = 1; i < n + 1; i++) {
        fact[i] = i * fact[i-1] % mod;
    }

    inv[n] = extpow(fact[n], mod - 2);
    // printf("inv[%d] = %lld\n", n, inv[n]);
    for (int i = n - 1; i >= 0; i--) {
        inv[i] = inv[i+1] * (i+1) % mod;
        // printf("inv[%d] = %lld\n", i, inv[i]);
    }

    // a <= b
    if (a > b) { swap(a, b); }

    ll ans = 0;
    for (ll j = 0; j <= k / b; j++) {
        if ((k - b * j) % a == 0) {
            ll i = (k - b * j) / a;
            if (i >= 0 && i <= n) {
                ans = (ans + C(n, i) * C(n, j)) % mod;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}