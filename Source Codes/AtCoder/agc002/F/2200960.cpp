#include <cassert>
#include <iostream>
#include <vector>
#define REP(i, n) for (int i = 0; (i) < int(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < int(n); ++ (i))
using ll = long long;
using namespace std;
template <typename X, typename T> auto vectors(X x, T a) { return vector<T>(x, a); }
template <typename X, typename Y, typename Z, typename... Zs> auto vectors(X x, Y y, Z z, Zs... zs) { auto cont = vectors(y, z, zs...); return vector<decltype(cont)>(x, cont); }

ll powmod(ll x, ll y, ll m) {
    assert (0 <= x and x < m);
    assert (0 <= y);
    ll z = 1;
    for (ll i = 1; i <= y; i <<= 1) {
        if (y & i) z = z * x % m;
        x = x * x % m;
    }
    return z;
}
ll modinv(ll x, ll p) {
    assert (x % p != 0);
    return powmod(x, p - 2, p);
}
template <int32_t MOD>
int32_t fact(int n) {
    static vector<int32_t> memo(1, 1);
    while (n >= memo.size()) {
        memo.push_back(memo.back() *(int64_t) memo.size() % MOD);
    }
    return memo[n];
}
template <int32_t PRIME>
int32_t inv_fact(int n) {
    static vector<int32_t> memo(1, 1);
    while (n >= memo.size()) {
        memo.push_back(memo.back() *(int64_t) modinv(memo.size(), PRIME) % PRIME);
    }
    return memo[n];
}
template <int MOD>
int choose(int n, int r) {
    assert (0 <= r and r <= n);
    return fact<MOD>(n) *(ll) inv_fact<MOD>(n - r) % MOD *(ll) inv_fact<MOD>(r) % MOD;
}

constexpr int mod = 1e9 + 7;
int solve(int n, int k) {
    if (k == 1) return 1;
    auto dp = vectors(n + 1, n + 1, int());
    dp[0][0] = 1;
    REP3 (i, 1, n + 1) {
        REP (j, i + 1) {
            if (i - 1 >= 0) {
                dp[i][j] += dp[i - 1][j];
            }
            if (j - 1 >= 0) {
                int remaining = (n - i) + (k - 1) * (n - (j - 1));
                dp[i][j] += dp[i][j - 1] *(ll) choose<mod>(remaining - 1, k - 2) % mod;
            }
            if (dp[i][j] >= mod) {
                dp[i][j] -= mod;
            }
        }
    }
    return dp[n][n] *(ll) fact<mod>(n) % mod;
}

int main() {
    int n, k; cin >> n >> k;
    cout << solve(n, k) << endl;
    return 0;
}