#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <numeric>
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

int main() {
    int n;
    cin >> n;

    vector<int> a1(n);
    vector<int> a2(n);
    rep(i, n) { cin >> a1[i]; }
    rep(i, n) { cin >> a2[i]; }

    vector<int> c1(n + 1);
    vector<int> c2(n + 1);
    for (int i = 1; i <= n; i++) {
        c1[i] = c1[i - 1] + a1[i - 1];
        c2[i] = c2[i - 1] + a2[i - 1];
    }

    int ans = 0;
    rep(i, n) { ans = max(ans, c1[i + 1] + c2[n] - c2[i]); }

    cout << ans << endl;
    return 0;
}