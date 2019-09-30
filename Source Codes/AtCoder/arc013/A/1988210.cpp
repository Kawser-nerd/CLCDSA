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

int solve(int n, int m, int l, int p, int q, int r) {
    return (n / p) * (m / q) * (l / r);
}

int main() {
    int n, m, l;
    int p, q, r;
    cin >> n >> m >> l;
    cin >> p >> q >> r;

    int ans = 0;
    ans = max(ans, solve(n, m, l, p, q, r));
    ans = max(ans, solve(n, m, l, p, r, q));
    ans = max(ans, solve(n, m, l, q, r, p));
    ans = max(ans, solve(n, m, l, q, p, r));
    ans = max(ans, solve(n, m, l, r, p, q));
    ans = max(ans, solve(n, m, l, r, q, p));
    cout << ans << endl;

    return 0;
}