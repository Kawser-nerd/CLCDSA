#include <iostream>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

ll dp[200010];

ll mod_pow(ll x, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

ll mod_inv(ll x) {
    return mod_pow(x, MOD-2) % MOD;
}

ll nCr(int n, int r) {
    return (dp[n] * mod_inv(dp[r]) % MOD) * mod_inv(dp[n-r]) % MOD;
}

int main() {
    int n, k;
    cin >> n >> k;
    dp[0] = dp[1] = 1;
    for (int i=2;i<=n+k;i++) {
        dp[i] = i * dp[i-1] % MOD;
    }
    ll res = nCr(n - 1 + k, n - 1);
    cout << res << endl;
}