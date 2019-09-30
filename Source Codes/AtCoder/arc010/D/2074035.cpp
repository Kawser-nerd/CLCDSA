#include <algorithm>
#include <cmath>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using ll = long long int;
#define int ll

const int MOD = 1e9 + 7;
const int INF = 5e18;

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

void dfs1(int n, const vector2<bool>& g, int v, vector<bool>& visited,
          stack<int>& memo) {
    visited[v] = true;

    rep(i, n) {
        if (g[v][i] && !visited[i]) {
            dfs1(n, g, i, visited, memo);
        }
    }

    memo.push(v);
}

void dfs2(int n, const vector2<bool>& g, int v, vector<int>& comp, int id) {
    comp[v] = id;

    rep(i, n) {
        if (g[i][v] && comp[i] == -1) {
            dfs2(n, g, i, comp, id);
        }
    }
}

vector<int> strongly_connected_component(int n, const vector2<bool>& g) {
    stack<int> memo;

    vector<bool> visited(n);
    rep(i, n) {
        if (visited[i]) {
            continue;
        }
        dfs1(n, g, i, visited, memo);
    }

    int id = 0;
    vector<int> comp(n, -1);

    while (!memo.empty()) {
        int v = memo.top();
        memo.pop();

        if (comp[v] != -1) {
            continue;
        }

        dfs2(n, g, v, comp, id);
        id++;
    }

    return comp;
}

int solve(int n, int m, const vector<int>& fy, const vector<int>& fx,
          const vector<int>& sy, const vector<int>& sx) {
    vector<int> ds(n, INF);

    rep(i, n) {
        int d = INF;
        rep(j, m) {
            int dy = abs(fy[i] - sy[j]);
            int dx = abs(fx[i] - sx[j]);
            d = min(d, dy * dy + dx * dx);
        }
        ds[i] = d;
    }

    vector2<bool> g = init_vector2(n, n, false);
    rep(i, n) {
        rep(j, n) {
            if (i == j) {
                continue;
            }
            int dy = abs(fy[i] - fy[j]);
            int dx = abs(fx[i] - fx[j]);
            if ((dy * dy + dx * dx) < ds[i]) {
                g[i][j] = true;
            }
        }
    }

    vector<int> comp = strongly_connected_component(n, g);
    int k = *max_element(comp.begin(), comp.end()) + 1;

    vector2<bool> dag = init_vector2(k, k, false);
    rep(i, n) {
        rep(j, n) {
            if (g[i][j]) {
                dag[comp[i]][comp[j]] = true;
            }
        }
    }

    int cnt = 0;
    rep(i, k) {
        bool is_root = true;
        rep(j, k) {
            if(i == j){
                continue;
            }
            if (dag[j][i]) {
                is_root = false;
                break;
            }
        }
        if (is_root) {
            cnt++;
        }
    }

    return cnt;
}

signed main() {
    int n;
    scanf("%lld", &n);

    vector<int> fx(n);
    vector<int> fy(n);
    rep(i, n) { scanf("%lld %lld", &fx[i], &fy[i]); }

    int m;
    scanf("%lld", &m);

    vector<int> sx(m);
    vector<int> sy(m);
    rep(i, m) { scanf("%lld %lld", &sx[i], &sy[i]); }

    printf("%lld\n", solve(n, m, fy, fx, sy, sx));

    return 0;
}