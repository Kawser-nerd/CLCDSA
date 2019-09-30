#include <algorithm>
#include <complex>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
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

using std::pair;
using std::make_pair;

typedef long long int ll;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

class edge {
   public:
    ll to, cost;
    edge() {}
    edge(ll to, ll cost) : to(to), cost(cost) {}
};

vector<ll> dijkstra(const vector<vector<edge>>& g, ll s) {
    vector<ll> d(g.size(), INF);
    d[s] = 0;

    typedef pair<ll, ll> P;
    priority_queue<P, vector<P>, std::greater<P>> q;
    q.push(make_pair(0, s));

    while (!q.empty()) {
        P tmp = q.top();
        q.pop();

        int v = tmp.second;
        int c = tmp.first;
        if (c > d[v]) {
            continue;
        }

        for (const edge& e : g[v]) {
            ll alt = d[v] + e.cost;
            if (alt < d[e.to]) {
                d[e.to] = alt;
                q.push(make_pair(alt, e.to));
            }
        }
    }

    return d;
}

int main() {
    ll n, m, t;
    cin >> n >> m >> t;

    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<vector<edge>> g0(n);
    vector<vector<edge>> g1(n);
    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g0[a].push_back(edge(b, c));
        g1[b].push_back(edge(a, c));
    }

    vector<ll> d0 = dijkstra(g0, 0);
    vector<ll> d1 = dijkstra(g1, 0);

    ll ans = -1;
    for (ll i = 0; i < n; i++) {
        if (d0[i] == INF || d1[i] == INF) {
            continue;
        }
        if (d0[i] + d1[i] >= t) {
            continue;
        }
        ans = max(ans, v[i] * (t - d0[i] - d1[i]));
    }

    cout << ans << endl;

    return 0;
}