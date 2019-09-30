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

int main() {
    ll n;
    cin >> n;

    vector<ll> t(n);
    rep(i, n) { cin >> t[i]; }

    sort(t.begin(), t.end());

    ll time = 0;
    ll pena = 0;
    rep(i, n) {
        time += t[i];
        pena += time;
    }

    cout << pena << endl;

    vector<ll> a(1e4 + 1);
    rep(i, n) { a[t[i]]++; }

    ll comb = 1;
    rep(i, 1e4 + 1) {
        comb = comb * fact_mod(a[i]) % MOD;
    }

    cout << comb << endl;

    return 0;
}