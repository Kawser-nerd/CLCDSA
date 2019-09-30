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

int main() {
    ll k;
    cin >> k;

    vector<ll> a(k);
    for (ll i = 0; i < k; i++) {
        cin >> a[i];
    }

    // [s, t)
    ll s = 2;
    ll t = 3;
    for (ll i = k - 1; i >= 0; i--) {
        const ll m = (t - 1) / a[i] - (s - 1) / a[i];
        if (m == 0) {
            cout << -1 << endl;
            return 0;
        }

        ll ss = -1;
        if (s % a[i] == 0) {
            ss = s;
        } else {
            ss = s + (a[i] - s % a[i]);
        }

        ll tt = ss + a[i] * m;

        // cout << a[i] << " " << ss << " " << tt << endl;
        s = ss;
        t = tt;
    }

    cout << s << " " << t - 1 << endl;

    return 0;
}