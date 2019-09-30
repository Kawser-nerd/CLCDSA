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

int main() {
    int n;
    cin >> n;

    vector<int> t(n + 1);
    vector<int> x(n + 1);
    vector<int> y(n + 1);
    t[0] = 0;
    x[0] = 0;
    y[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> x[i] >> y[i];
    }

    bool ans = true;
    rep(i, n) {
        int dxy = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
        int dt = t[i + 1] - t[i];
        if (dxy > dt) {
            ans = false;
            break;
        }
        if ((dt - dxy) % 2 != 0) {
            ans = false;
            break;
        }
    }
    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}