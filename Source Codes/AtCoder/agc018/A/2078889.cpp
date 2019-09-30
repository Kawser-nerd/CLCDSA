#include <algorithm>
#include <cmath>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
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

int gcd(int a, int b) {
    while (b != 0) {
        int m = a % b;
        a = b;
        b = m;
    }
    return a;
}

signed main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    rep(i, n) { cin >> a[i]; }

    int m = a[0];
    rep(i, n) { m = gcd(m, a[i]); }

    cout << (k <= *max_element(a.begin(), a.end()) && k % m == 0 ? "POSSIBLE"
                                                                 : "IMPOSSIBLE")
         << endl;

    return 0;
}