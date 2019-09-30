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

bool eval(ll n, const vector<ll>& xs, const vector<ll>& ys, ll px, ll py) {
    ll d = abs(xs[0] - px) + abs(ys[0] - py);
    for (ll i = 1; i < n; i++) {
        ll v = abs(xs[i] - px) + abs(ys[i] - py);
        if (v != d) {
            return false;
        }
    }
    return true;
}

int main() {
    ll n;
    cin >> n;

    vector<ll> xs(n);
    vector<ll> ys(n);
    for (ll i = 0; i < n; i++) {
        cin >> xs[i] >> ys[i];
    }

    ll k_min;
    ll k_max;
    ll l_min;
    ll l_max;
    k_min = k_max = xs[0] + ys[0];
    l_min = l_max = xs[0] - ys[0];
    for (ll i = 1; i < n; i++) {
        k_min = min(k_min, xs[i] + ys[i]);
        k_max = max(k_max, xs[i] + ys[i]);
        l_min = min(l_min, xs[i] - ys[i]);
        l_max = max(l_max, xs[i] - ys[i]);
    }
    ll d = max(k_max - k_min, l_max - l_min);

    vector<ll> px = {k_max - d / 2, k_min + d / 2};
    vector<ll> py = {l_max - d / 2, l_min + d / 2};
    for (ll i = 0; i < 2; i++) {
        for (ll j = 0; j < 2; j++) {
            ll x = (px[i] + py[i]) / 2;
            ll y = (px[i] - py[i]) / 2;
            if (eval(n, xs, ys, x, y)) {
                cout << x << " " << y << endl;
                return 0;
            }
        }
    }

    return 0;
}