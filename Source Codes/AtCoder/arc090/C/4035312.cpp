#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

template <typename T>
pair<vector<T>, vector<int>> dijkstra(const vector<vector<pair<int, T>>>& graph, int n, int s){
    typedef pair<T, int> PP;

    vector<T> d(n+1, INF);
    d[s] = 0;

    vector<int> p(n+1, -1);
    p[s] =  s;

    priority_queue<PP, vector<PP>, greater<PP>> que;
    que.emplace((T)0, s);

    while(!que.empty()){
        T w = que.top().first;
        int v = que.top().second;
        que.pop();

        if(d[v] < w){
            continue;
        }

        for(pair<int, T> edge : graph[v]){
            int u = edge.first;
            T nw = w + edge.second;
            if(nw < d[u]){
                d[u] = nw;
                p[u] = v;
                que.emplace(nw, u);
            }
        }
    }
    return make_pair(d, p);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--;
    t--;
    vector<vector<P>> edge(n, vector<P>());
    rep(i, m){
        int u, v, d;
        cin >> u >> v >> d;
        edge[u-1].emplace_back(v-1, d);
        edge[v-1].emplace_back(u-1, d);
    }

    pair<vector<int>, vector<int>> ps = dijkstra(edge, n, s);
    pair<vector<int>, vector<int>> pt = dijkstra(edge, n, t);
    vector<P> vs = vector<P>(n);
    vector<P> vt = vector<P>(n);
    rep(i, n){
        vs[i] = {ps.first[i], i};
        vt[i] = {pt.first[i], i};
    }
    sort(ALL(vs));
    sort(ALL(vt));

    vector<int> dp1(n), dp2(n);
    dp1[s] = dp2[t] = 1;
    rep(i, n){
        int v = vs[i].second;
        for(P p : edge[v]){
            int u = p.first;
            int d = p.second;

            if(ps.first[v] + d == ps.first[u]){
                dp1[u] += dp1[v];
                dp1[u] %= MOD;
            }
        }

        v = vt[i].second;
        for(P p : edge[v]){
            int u = p.first;
            int d = p.second;

            if(pt.first[v] + d == pt.first[u]){
                dp2[u] += dp2[v];
                dp2[u] %= MOD;
            }
        }
    }

    int ans = dp1[t] * dp1[t] % MOD;
    //cout << dp1[t] << " " << ans << endl;
    int st = ps.first[t];
    rep(v, n){
        if(ps.first[v] * 2 == st && ps.first[v] == pt.first[v]){
            int tmp = dp1[v] * dp1[v] % MOD * dp2[v] % MOD * dp2[v] % MOD;
            ans = (ans + MOD - tmp) % MOD;
            //cout << v << " " << ans << endl;
        }

        for(P p : edge[v]){
            int u = p.first;
            int d = p.second;
            int dv = ps.first[v];
            int du = ps.first[u];
            if(dv * 2 >= st || du * 2 <= st || dv + d != du || du + pt.first[u] != st){
                continue;
            }
            int tmp = dp1[v] * dp1[v] % MOD * dp2[u] % MOD * dp2[u] % MOD;
            ans = (ans + MOD - tmp) % MOD;
            //cout << v << " " << u << " " << dv << " " << du << " " << d << " " << ans << endl;
        }
    }
    cout << ans << endl;

    return 0;
}