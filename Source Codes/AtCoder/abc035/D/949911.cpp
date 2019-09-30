#include "math.h"
#include <algorithm>
#include <complex>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define ifor(i, a, b) for (int i = (a); i < (b); i++)
#define rfor(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
using namespace std;
typedef long double ld;
typedef long long int lli;
typedef complex<double> P;
const double eps = 1e-11;
int vex[4] = {1, 0, -1, 0};
int vey[4] = {0, 1, 0, -1};
typedef vector<double> Vec;
typedef vector<int> vec;
typedef vector<Vec> MAT;
typedef vector<vec> mat;
lli MOD = 1000000007;
#define MAX 100005
struct node {
    lli v, d;
    node(lli v, lli d) : v(v), d(d) {}
    bool operator<(const node& n) const { return d > n.d; }
};
struct edge {
    lli to, d;
    edge(lli to, lli d) : to(to), d(d) {}
};
lli V;
struct Graph {
    vector<edge> G[MAX];
    lli dist[MAX];  // shortest distance
    Graph()
    {
        rep(i, MAX)
        {
            G[i].clear();
            dist[i] = -1;
        }
    }
    void dijkstra(int s)
    {
        priority_queue<node> que;
        que.push(node(s, 0));
        while (!que.empty()) {
            lli v = que.top().v, d = que.top().d;
            que.pop();
            if (dist[v] >= 0 and dist[v] <= d)
                continue;
            dist[v] = d;
            for (int i = 0; i < G[v].size(); i++)
                que.push(node(G[v][i].to, d + G[v][i].d));
        }
    }
};
int main()
{

    lli N, M, T, a, b, c, A[MAX];
    cin >> N >> M >> T;
    Graph g1, g2;
    rep(i, N)
    {
        cin >> A[i];
    }
    rep(i, M)
    {
        cin >> a >> b >> c;
        a--, b--;
        g1.G[a].push_back(edge(b, c));
        g2.G[b].push_back(edge(a, c));
    }
    g1.dijkstra(0);
    g2.dijkstra(0);
    lli ans = -1;
    rep(i, N)
    {

        lli d = T - g1.dist[i] - g2.dist[i];
        if (g1.dist[i] != -1 && g2.dist[i] != -1 && d >= 0) {
            ans = max(ans, d * A[i]);
        }
    }
    cout << ans << endl;
}