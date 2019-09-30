#include <algorithm>
#include <iostream>
#include <vector>
#define SZ(x) ((int) (x).size())
using namespace std;

const int MOD = (int) 1e9 + 7;

int Pow(int x, int y) {
    int ret = 1;
    for (;y > 0; y /= 2) {
        if (y & 1) {
            ret = ret * (int64_t) x % MOD;
        }
        x = x * (int64_t) x % MOD;
    }
    return ret;
}

int invMod(int x) {
    return Pow(x, MOD - 2);
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 2) {
        cout << 1 << '\n';
    } else if (n == 3) {
        cout << 4 << '\n';
    } else {
        vector<int> fact(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            fact[i] = fact[i - 1] * (int64_t) i % MOD;
        }
        vector<int> inv(n + 1, 0);
        inv[1] = 1;
        for (int i = 2; i <= n; ++i) {
            inv[i] = (MOD - MOD / i) * (int64_t) inv[MOD % i] % MOD;
        }
        vector<int> ifact(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            ifact[i] = ifact[i - 1] * (int64_t) inv[i] % MOD;
        }
        auto comb = [&](int n, int k) -> int {
            if (n < 0 || k < 0 || k > n) {
                return 0;
            }
            return fact[n] * (int64_t) ifact[n - k]  % MOD * ifact[k] % MOD;
        };
        int ans = fact[n - 1] * (int64_t) n % MOD;
        for (int k = 0; k < n; ++k) {
            int v = comb(n - 1 - k - 1, k);
            v = v * (int64_t) fact[k] % MOD;
            v = v * (int64_t) fact[n - k - 1] % MOD;
            ans = (ans - v + MOD) % MOD;
        }
        cout << ans << '\n';
    }
}