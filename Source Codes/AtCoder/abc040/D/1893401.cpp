#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::stack;
using std::priority_queue;

using std::min;
using std::max;
using std::sort;
using std::abs;

typedef long long int ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

class unionfind {
   private:
    vector<int> p;
    vector<int> h;
    vector<int> w;

   public:
    unionfind(int n) : p(n, -1), h(n, 0), w(n, 1) {}

    int find(int u) {
        if (p[u] == -1) {
            return u;
        }
        return p[u] = find(p[u]);
    }

    void unite(int u, int v) {
        const int u_rt = find(u);
        const int v_rt = find(v);

        if (u_rt == v_rt) {
            return;
        }

        if (h[u_rt] > h[v_rt]) {
            p[v_rt] = u_rt;
            w[u_rt] += w[v_rt];
        } else {
            p[u_rt] = v_rt;
            w[v_rt] += w[u_rt];
            if (h[u_rt] == h[v_rt]) {
                h[v_rt]++;
            }
        }
    }

    int weight(int u) { return w[find(u)]; }
    bool same(int u, int v) { return find(u) == find(v); }
};

class edge {
   public:
    int u, v, w;
    edge() {}
    edge(int u, int v, int w) : u(u), v(v), w(w) {}

    bool operator<(const edge& e) const { return w < e.w; }
    bool operator>(const edge& e) const { return w > e.w; }
};

class query {
   public:
    int i;
    int v;
    int w;
    query() {}
    query(int i, int v, int w) : i(i), v(v), w(w) {}

    bool operator<(const query& q) const { return w < q.w; }
    bool operator>(const query& q) const { return w > q.w; }
};

vector<int> solve(int n, const vector<edge> es, const vector<query> qs) {
    vector<int> ans(qs.size(), -1);

    unionfind uf(n);

    size_t ep = 0;
    for (const query& q : qs) {
        for (; ep < es.size() && es[ep].w > q.w; ep++) {
            uf.unite(es[ep].u, es[ep].v);
        }
        ans[q.i] = uf.weight(q.v);
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<edge> es(m);
    for (int i = 0; i < m; i++) {
        int a, b, y;
        cin >> a >> b >> y;
        a--;
        b--;
        es[i] = edge(a, b, y);
    }
    sort(es.begin(), es.end(), std::greater<edge>());

    int q;
    cin >> q;

    vector<query> qs(q);
    for (int i = 0; i < q; i++) {
        int v, w;
        cin >> v >> w;
        v--;
        qs[i] = query(i, v, w);
    }
    sort(qs.begin(), qs.end(), std::greater<query>());

    vector<int> ans = solve(n, es, qs);
    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}