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

int dfs(const vector2<int>& g, const vector<int>& h, int v,
        vector<bool> visited) {
    if (visited[v]) {
        return 0;
    }

    visited[v] = true;
    int route = 0;
    for (int u : g[v]) {
        if (visited[u]) {
            continue;
        }
        route += dfs(g, h, u, visited);
    }

    return route == 0 && h[v] == 0 ? 0 : route + 1;
}

int main() {
    int n, x;
    cin >> n >> x;
    x--;

    vector<int> h(n);
    rep(i, n) { cin >> h[i]; }

    bool found = false;
    rep(i, n) {
        if (h[i] == 1) {
            found = true;
            break;
        }
    }
    if (!found) {
        cout << 0 << endl;
        return 0;
    }

    vector2<int> g(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<bool> visited(n);
    cout << 2 * dfs(g, h, x, visited) - 2 << endl;

    return 0;
}