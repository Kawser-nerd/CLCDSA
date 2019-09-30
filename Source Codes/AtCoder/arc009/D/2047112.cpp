#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using ll = long long int;
const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 373;

#define rep(i, n) for (ll i = 0; i < (n); ++i)

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

class edge {
   public:
    ll u;
    ll v;
    ll w;
    edge() : u(0), v(0), w(0) {}
    edge(ll u, ll v, ll w) : u(u), v(v), w(w) {}

    bool operator==(const edge& e) const {
        return u == e.u && v == e.v && w == e.w;
    }

    bool operator<(const edge& e) const {
        if (w == e.w) {
            if (u == e.u) {
                return v < e.v;
            }
            return u < e.u;
        }
        return w < e.w;
    }
};

class union_find_tree {
   private:
    vector<ll> p;
    vector<ll> h;
    vector<ll> w;

   public:
    union_find_tree(ll n) : p(n, -1), h(n, 0), w(n, 1) {}

    ll find(ll u) {
        if (p[u] == -1) {
            return u;
        }
        return p[u] = find(p[u]);
    }

    void unite(ll u, ll v) {
        const ll u_rt = find(u);
        const ll v_rt = find(v);

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

    ll weight(ll u) { return w[find(u)]; }
    bool same(ll u, ll v) { return find(u) == find(v); }
};

ll popcnt(ll s) { return __builtin_popcount(s); }

bool is_tree(ll n, ll m, const vector<edge>& es, ll s) {
    if (popcnt(s) != n - 1) {
        return false;
    }

    union_find_tree uf(n);
    rep(i, m) {
        if (not(s & (1 << i))) {
            continue;
        }
        if (uf.same(es[i].u, es[i].v)) {
            return false;
        }
        uf.unite(es[i].u, es[i].v);
    }

    return true;
}

// n : number of vertex
// m : number of edge
// es : set of edge
// O( 2^m * n * \alpha(n) )
vector<ll> enum_tree(ll n, ll m, const vector<edge>& es) {
    vector<ll> ans(77 * 6 + 1, 0);

    for (ll s = 0; s < (1 << m); s++) {
        if (!is_tree(n, m, es, s)) {
            continue;
        }

        ll sum = 0;
        rep(i, m) {
            if (s & (1 << i)) {
                sum += es[i].w;
            }
        }
        ans[sum]++;
    }

    return ans;
}

map<ll, ll> compress(const vector<ll>& a) {
    vector<ll> b(a);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    map<ll, ll> c;
    ll m = b.size();
    rep(i, m) { c[b[i]] = i; }

    return c;
}

int main() {
    ll a, t, k;
    cin >> a >> t >> k;

    vector<ll> n(a);
    vector2<bool> c = init_vector2<bool>(a, t, false);
    rep(i, a) {
        cin >> n[i];
        rep(j, n[i]) {
            ll x;
            cin >> x;
            c[i][x - 1] = true;
        }
    }

    ll m;
    cin >> m;

    ll w_sum = 0;

    vector2<edge> g(a);
    rep(i, m) {
        edge e;
        cin >> e.u >> e.v >> e.w;
        e.u--;
        e.v--;
        w_sum += e.w;

        rep(j, a) {
            if (c[j][e.u] && c[j][e.v]) {
                g[j].push_back(e);
            }
        }
    }

    rep(i, a) {
        vector<ll> tmp;
        rep(j, t) {
            if (c[i][j]) {
                tmp.push_back(j);
            }
        }
        map<ll, ll> cmap = compress(tmp);
        rep(j, (ll)g[i].size()) {
            g[i][j].u = cmap[g[i][j].u];
            g[i][j].v = cmap[g[i][j].v];
        }
    }

    vector2<ll> ws(a);
    rep(i, a) { ws[i] = enum_tree(n[i], g[i].size(), g[i]); }

    vector2<ll> dp = init_vector2<ll>(a + 1, a * 77 * 6 + 1, 0);
    dp[0][0] = 1;
    for (ll i = 1; i <= a; i++) {
        for (ll j = 0; j <= a * 77 * 6; j++) {
            ll sum = 0;
            for (ll w = 0; w <= 77 * 6; w++) {
                if (w <= j && ws[i - 1][w] > 0) {
                    sum += dp[i - 1][j - w] * ws[i - 1][w];
                    sum = sum >= INF ? INF : sum;
                }
            }
            dp[i][j] = sum;
        }
    }


    ll ans = -1;
    ll sum = 0;
    for (ll j = a * 77 * 6; j >= 0; j--) {
        sum += dp[a][j];
        if (sum >= k) {
            ans = j;
            break;
        }
    }

    if (ans == -1) {
        cout << -1 << endl;
    } else {
        cout << w_sum - ans << endl;
    }

    return 0;
}