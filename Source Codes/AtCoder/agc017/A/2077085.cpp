#include <algorithm>
#include <cmath>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using ll = long long int;
#define int ll

const int MOD = 1e9 + 7;
const int INF = 1e15 + 373;

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

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (T e : v) {
        os << e << ", ";
    }
    os << "]";
    return os;
}

signed main() {
    int n, p;
    cin >> n >> p;

    vector<int> a(n);
    rep(i, n) { cin >> a[i]; }

    int cnt0 = 0;
    int cnt1 = 0;
    rep(i, n) {
        if (a[i] % 2 == 0) {
            cnt0++;
        }
        if (a[i] % 2 == 1) {
            cnt1++;
        }
    }

    if (p == 0) {
        cout << (1LL << (cnt0 + max(cnt1 - 1, 0LL))) << endl;
    } else {
        cout << (cnt1 == 0 ? 0LL : 1LL << (cnt0 + max(cnt1 - 1, 0LL))) << endl;
    }

    return 0;
}