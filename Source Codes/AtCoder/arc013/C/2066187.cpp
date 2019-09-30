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

signed main() {
    int n;
    cin >> n;

    int sum = 0;
    rep(i, n) {
        int tx, ty, tz;
        cin >> tx >> ty >> tz;

        int m;
        cin >> m;

        int xmin = INF, xmax = -INF;
        int ymin = INF, ymax = -INF;
        int zmin = INF, zmax = -INF;
        rep(j, m) {
            int hx, hy, hz;
            cin >> hx >> hy >> hz;

            xmin = min(xmin, hx);
            xmax = max(xmax, hx);
            ymin = min(ymin, hy);
            ymax = max(ymax, hy);
            zmin = min(zmin, hz);
            zmax = max(zmax, hz);
        }
        int v0 = abs(xmin - 0);
        int v1 = abs(xmax - (tx - 1));
        int v2 = abs(ymin - 0);
        int v3 = abs(ymax - (ty - 1));
        int v4 = abs(zmin - 0);
        int v5 = abs(zmax - (tz - 1));
        sum ^= v0 ^ v1 ^ v2 ^ v3 ^ v4 ^ v5;
    }

    cout << (sum == 0 ? "LOSE" : "WIN") << endl;
    return 0;
}