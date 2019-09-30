#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using ll = long long int;
const ll MOD = 1'777'777'777;
const ll INF = 1e9 + 373;

#define rep(i, n) for (ll i = 0; i < (n); ++i)

template <typename T>
using vector2 = vector<vector<T>>;
template <typename T>
vector2<T> init_vector2(size_t n0, size_t n1, T e = T()) {
    return vector2<T>(n0, vector<T>(n1, e));
}

template <typename T>
using vector3 = vector<vector<vector<T>>>;
template <typename T>
vector3<T> init_vector3(size_t n0, size_t n1, size_t n2, T e = T()) {
    return vector3<T>(n0, vector2<T>(n1, vector<T>(n2, e)));
}

ll pow_mod(ll x, ll n) {
    ll ans = 1;
    ll xx = x;
    for (ll m = n; m > 0; m >>= 1) {
        if (m & 1) {
            ans = ans * xx % MOD;
        }
        xx = xx * xx % MOD;
    }
    return ans;
}

ll inv_mod(ll n) {
    ll ans = pow_mod(n, MOD - 2);
    return ans;
}

ll fact_mod(ll n) {
    static vector<ll> memo = {1};
    if (n < (ll)memo.size()) {
        return memo[n];
    }
    for (ll i = memo.size(); i <= n; i++) {
        memo.push_back(i * memo[i - 1] % MOD);
    }
    return memo[n];
}

ll comb_mod(ll n, ll r) {
    ll ans = 1;
    for (ll i = 0; i < r; i++) {
        ans = ans * ((n - i + MOD) % MOD) % MOD;
    }
    return ans * inv_mod(fact_mod(r)) % MOD;
}

int main() {
    ll n, k;
    cin >> n >> k;

    vector<ll> c(k + 1);
    c[0] = 1;
    c[1] = 0;
    c[2] = 1;
    for (ll i = 3; i <= k; i++) {
        c[i] = (c[i - 1] + c[i - 2]) % MOD * (i - 1) % MOD;
    }

    ll ans = c[k] * comb_mod(n, k) % MOD;
    cout << ans << endl;

    return 0;
}