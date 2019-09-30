#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::stack;
using std::priority_queue;
using std::pair;
using std::make_pair;

using std::min;
using std::max;
using std::sort;
using std::abs;

using std::fixed;
using std::setprecision;
using std::setw;

using ll = long long int;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 373;

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

ll solve(ll n, const vector<ll>& a) {
    if (a[0] != 0) {
        return 0;
    }

    ll m = -1;
    for (ll i = 0; i < n; i++) {
        m = max(m, a[i]);
    }

    vector<ll> c(m + 1);
    for (ll i = 0; i < n; i++) {
        c[a[i]]++;
    }

    if (c[0] != 1) {
        return 0;
    }

    for (ll i = 0; i <= m; i++) {
        if (c[i] == 0) {
            return 0;
        }
    }

    ll ans = 1;
    for (ll i = 1; i <= m; i++) {
        ans = ans * pow_mod(pow_mod(2, c[i - 1]) - 1, c[i]) % MOD;
        ans = ans * pow_mod(2, c[i] * (c[i] - 1) / 2) % MOD;
    }

    return ans;
}

int main() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << solve(n, a) << endl;

    return 0;
}