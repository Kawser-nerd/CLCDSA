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

int solve(const vector2<int>& g, int v) {
    const int m = g[v].size();
    if (m == 0) {
        return 0;
    }

    vector<int> h(m);
    for (int i = 0; i < m; i++) {
        h[i] = solve(g, g[v][i]);
    }
    sort(h.begin(), h.end());

    int ans = 0;
    for (int i = 0; i < m; i++) {
        ans = max(ans, h[i] + m - i);
    }
    return ans;
}

signed main() {
    int n;
    cin >> n;

    vector2<int> g = init_vector2<int>(n, 0);
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        a--;
        g[a].push_back(i);
    }

    cout << solve(g, 0) << endl;

    return 0;
}