#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using ll = long long int;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 373;

#define rep(i, n) for (int i = 0; i < (n); ++i)

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

vector<pair<ll, ll>> factorize(ll n) {
    vector<pair<ll, ll>> ans;

    for (ll i = 2; i * i <= n; i++) {
        if (n % i != 0) {
            continue;
        }

        ll cnt = 0;
        while (n % i == 0) {
            n /= i;
            cnt++;
        }
        ans.push_back(make_pair(i, cnt));
    }

    if (n != 1) {
        ans.push_back(make_pair(n, 1));
    }

    return ans;
}

int main() {
    ll n, m;
    cin >> n >> m;

    n = abs(n);

    vector<pair<ll, ll>> f = factorize(n);

    ll ans = 1;
    // sign
    for (int i = 0; i < m - 1; i++) {
        ans = ans * 2 % MOD;
    }

    // divider
    for (pair<ll, ll> p : f) {
        ll k = p.second;
        ans = ans * fact_mod(k + m - 1) % MOD;
        ans = ans * inv_mod(fact_mod(k)) % MOD;
        ans = ans * inv_mod(fact_mod(m - 1)) % MOD;
    }

    cout << ans << endl;

    return 0;
}