#include <cassert>
#include <cstdio>
#include <functional>
#include <tuple>
#include <vector>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
using namespace std;
template <class T> inline void setmax(T & a, T const & b) { a = max(a, b); }
template <typename X, typename T> auto vectors(X x, T a) { return vector<T>(x, a); }
template <typename X, typename Y, typename Z, typename... Zs> auto vectors(X x, Y y, Z z, Zs... zs) { auto cont = vectors(y, z, zs...); return vector<decltype(cont)>(x, cont); }

inline int singleton(int i) { return 1 << i; }
inline int setminus(int s, int t) { return s & ~ t; }
inline int complement(int s, int n) { return setminus((1 << n) - 1, s); }
inline bool is_a(int i, int s) { return s & (1 << i); }

vector<int> calculate_component_wieghts(int n, vector<tuple<int, int, int> > const & edges) {
    vector<int> component_wieght(1 << n);
    repeat (x, 1 << n) {
        for (auto edge : edges) {
            int a, b, c; tie(a, b, c) = edge;
            if (is_a(a, x) and is_a(b, x)) {
                component_wieght[x] += c;
            }
        }
    }
    return component_wieght;
}

vector<int> enumerate_paths(int n, vector<vector<pair<int, int> > > const & g) {
    const int start = 0;
    const int goal = n - 1;
    vector<vector<int> > dp = vectors(n, 1 << n, -1);
    dp[start][1 << start] = 0;
    repeat (used, 1 << n) {
        repeat (i, n) if (is_a(i, used) and dp[i][used] != -1) {
            for (auto edge : g[i]) {
                int j, cost; tie(j, cost) = edge;
                if (is_a(j, used)) continue;
                setmax(dp[j][used | singleton(j)], dp[i][used] + cost);
            }
        }
    }
    return dp[goal];
}

int use_remaining_edges(int used, int n, vector<tuple<int, int, int> > const & edges, vector<int> const & component_wieght) {
    vector<int> cur(1 << n, -1), prv;
    cur[0] = 0;
    int acc = 0;
    repeat (i, n) if (is_a(i, used)) {
        cur.swap(prv);
        cur.assign(1 << n, -1);
        int z = complement(acc | used, n);
        for (int x = 0; ; x = (x - z) & z) { // x \subseteq z
            int zx = z ^ x; // z \setminus x
            for (int y = 0; ; y = (y - zx) & zx) { // y \subseteq zx
                setmax(cur[x | acc | y | singleton(i)], prv[x | acc] + component_wieght[y | singleton(i)]);
                if (y == zx) break;
            }
            if (x == z) break;
        }
        acc  ^= singleton(i);
        used ^= singleton(i);
    }
    return cur[(1 << n) - 1];
}

int solve(int n, vector<vector<pair<int, int> > > const & g, vector<tuple<int, int, int> > const & edges) {
    auto path = enumerate_paths(n, g);
    auto component_wieght = calculate_component_wieghts(n, edges);
    int result = 0;
    repeat (used, 1 << n) if (path[used] != -1) {
        setmax(result, path[used] + use_remaining_edges(used, n, edges, component_wieght));
    }
    int total_cost = 0; for (auto edge : edges) total_cost += get<2>(edge);
    return total_cost - result;
}

int main() {
    // input
    int n, m; scanf("%d%d", &n, &m);
    vector<vector<pair<int, int> > > g(n);
    vector<tuple<int, int, int> > edges(m);
    repeat (i, m) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c); -- a; -- b;
        edges[i] = { a, b , c };
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    // solve
    int result = solve(n, g, edges);
    // output
    printf("%d\n", result);
    return 0;
}