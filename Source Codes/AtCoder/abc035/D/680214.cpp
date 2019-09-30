#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#define repeat(i,n) for (int i = 0; (i) < (n); ++(i))
typedef long long ll;
template <class T> bool setmax(T & l, T const & r) { if (not (l < r)) return false; l = r; return true; }
using namespace std;
using namespace boost;
using graph_t = adjacency_list<vecS, vecS, directedS, no_property, property<edge_weight_t, ll> >;
int main() {
    int n, m, t; cin >> n >> m >> t;
    vector<int> a(n); repeat (i,n) cin >> a[i];
    graph_t g(n), g_rev(n);
    repeat (i,m) {
        int x, y, z; cin >> x >> y >> z; -- x; -- y;
        add_edge(x, y, z, g);
        add_edge(y, x, z, g_rev);
    }
    vector<ll> dist(n), dist_rev(n);
    vector<int> parent(n), parent_rev(n);
    dijkstra_shortest_paths(g,     0, distance_map(dist    .data()).predecessor_map(parent    .data()));
    dijkstra_shortest_paths(g_rev, 0, distance_map(dist_rev.data()).predecessor_map(parent_rev.data()));
    ll ans = 0;
    repeat (i,n) {
        if (i != 0 and (parent[i] == i or parent_rev[i] == i)) continue;
        setmax(ans, a[i] * (t - dist[i] - dist_rev[i]));
    }
    cout << ans << endl;
    return 0;
}