#include <algorithm>
#include <cmath>
#include <complex>
#include <deque>
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
    int all, n, q;
    cin >> all >> n >> q;

    vector<int> l(n);
    rep(i, n) { cin >> l[i]; }

    vector<int> a(n - 1);
    for (int i = 0; i < n - 1; i++) {
        a[i] = l[i + 1] - l[i] - 1;
    }
    sort(a.begin(), a.end());

    vector<int> c(n);
    c[0] = 0;
    for (int i = 1; i < n; i++) {
        c[i] = a[i - 1] + c[i - 1];
    }

    rep(i, q) {
        int x, y;
        cin >> x >> y;

        int ind = upper_bound(a.begin(), a.end(), x + y) - a.begin();

        int ans = n;
        ans += c[ind];
        ans += (x + y) * ((n - 1) - ind);
        ans += min(x, l[0] - 1);
        ans += min(y, all - l[n - 1]);

        cout << ans << endl;
    }

    return 0;
}