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

template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
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

map<int, int> compress(const vector<int>& a) {
    vector<int> b(a);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    map<int, int> c;
    int m = b.size();
    rep(i, m) { c[b[i]] = i; }

    return c;
}

/********************************************************************************/

class edge {
   public:
    int from;
    int to;
    int cost;
    int rev;
    edge() : from(0), to(0), cost(0), rev(0) {}
    edge(int from, int to, int cost, int rev)
        : from(from), to(to), cost(cost), rev(rev) {}

    bool operator==(const edge& e) const {
        return from == e.from && to == e.to && cost == e.cost;
    }

    bool operator<(const edge& e) const {
        if (cost != e.cost) {
            return cost < e.cost;
        }
        return from == e.from ? to < e.to : from < e.from;
    }
};

void add_edge(vector2<edge>& g, int from, int to, int cost) {
    g[from].push_back(edge(from, to, cost, g[to].size()));
    g[to].push_back(edge(to, from, 0, g[from].size() - 1));
}

vector2<edge> build_graph(int m, const vector<pair<int, int>>& ps) {
    vector2<edge> g(2 * m + 2);

    int s = 2 * m;
    int t = 2 * m + 1;

    for (const pair<int, int>& p : ps) {
        add_edge(g, p.first, p.second + m, 1);
        add_edge(g, p.second, p.first + m, 1);
    }

    rep(i, m) {
        add_edge(g, s, i, 1);
        add_edge(g, i + m, t, 1);
    }

    return g;
}

vector<int> bfs(int n, const vector2<edge>& g, int s) {
    vector<int> dep(n, -1);
    dep[s] = 0;

    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (const edge& e : g[v]) {
            if (e.cost > 0 && dep[e.to] == -1) {
                dep[e.to] = dep[v] + 1;
                q.push(e.to);
            }
        }
    }

    return dep;
}

int dfs(int n, vector2<edge>& g, const vector<int>& dep, int v, int t, int f,
        vector<int>& itr) {
    if (v == t) {
        return f;
    }

    for (; itr[v] < (int)g[v].size(); itr[v]++) {
        const edge& e = g[v][itr[v]];
        if (e.cost > 0 && dep[v] < dep[e.to]) {
            int ans = dfs(n, g, dep, e.to, t, min(f, e.cost), itr);
            if (ans > 0) {
                g[v][itr[v]].cost -= ans;
                g[e.to][e.rev].cost += ans;
                return ans;
            }
        }
    }
    return 0;
}

int maxflow(int n, const vector2<edge>& g_, int s, int t) {
    vector2<edge> g(g_);
    int ans = 0;

    while (1) {
        vector<int> dep = bfs(n, g, s);
        if(dep[t] == -1){
            break;
        }

        vector<int> itr(n);
        while (1) {
            int flow = dfs(n, g, dep, s, t, INF, itr);
            if(flow == 0){
                break;
            }
            ans += flow;
        }
    }

    return ans;
}

signed main() {
    int n;
    cin >> n;

    vector<int> xs(n);
    vector<int> ys(n);
    vector<int> zs(n);
    rep(i, n) { cin >> xs[i] >> ys[i] >> zs[i]; }

    vector<pair<int, int>> ps;
    rep(i, n) {
        int x = xs[i];
        int y = ys[i];
        int z = zs[i];
        for (int j = 1; j < x; j++) {
            int v0 = j * y * z;
            int v1 = (x - j) * y * z;
            ps.push_back(make_pair(min(v0, v1), max(v0, v1)));
        }
        for (int j = 1; j < y; j++) {
            int v0 = x * j * z;
            int v1 = x * (y - j) * z;
            ps.push_back(make_pair(min(v0, v1), max(v0, v1)));
        }
        for (int j = 1; j < z; j++) {
            int v0 = x * y * j;
            int v1 = x * y * (z - j);
            ps.push_back(make_pair(min(v0, v1), max(v0, v1)));
        }
    }

    sort(ps.begin(), ps.end());
    ps.erase(unique(ps.begin(), ps.end()), ps.end());

    vector<int> vs;
    for (const pair<int, int>& p : ps) {
        vs.push_back(p.first);
        vs.push_back(p.second);
    }

    map<int, int> cmap = compress(vs);

    rep(i, (int)ps.size()) {
        ps[i].first = cmap[ps[i].first];
        ps[i].second = cmap[ps[i].second];
    }

    int m = cmap.size();
    vector2<edge> g = build_graph(m, ps);
    int ans = maxflow(g.size(), g, 2 * m, 2 * m + 1);
    cout << ans + (2 * m - 2 * ans) << endl;

    return 0;
}