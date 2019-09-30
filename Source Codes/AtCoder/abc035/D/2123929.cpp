#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

class edge{
    public:
        int u, v, w;
        edge() : u(0), v(0), w(0) {}
        edge(int u, int v, int w) : u(u), v(v), w(w) {}

        bool operator==(const edge& e) const {
            return u == e.u && v == e.v && w == e.w;
        }

        bool operator<(const edge& e) const {
            if(w != e.w){
                return w < e.w;
            }

            return u == e.u ? v < e.v : u < e.u;
        }
};

pair<vector<int>, vector<int>> dijkstra(const vector<vector<edge>>& graph, int n, int s){
    vector<int> d(n+1, INF);
    d[s] = 0;

    vector<int> p(n+1, -1);
    p[s] =  s;

    priority_queue<P, vector<P>, greater<P>> que;
    que.push(make_pair(0, s));

    while(!que.empty()){
        int dist = que.top().first;
        int ver = que.top().second;
        que.pop();

        if(d[ver] < dist){
            continue;
        }

        for(int i = 0; i < (int)graph[ver].size(); i++){
            edge e = graph[ver][i];
            if(d[e.v] > d[ver] + e.w){
                d[e.v] = d[ver] + e.w;
                p[e.v] = e.u;
                que.push(make_pair(d[e.v], e.v));
            }
        }
    }
    return make_pair(d, p);
}

signed main(){
    int n, m, t;
    cin >> n >> m >> t;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<edge>> graph(n+1), rev(n+1);
    rep(i, m){
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back(edge(a, b, c));
        rev[b].push_back(edge(b, a, c));
    }

    pair<vector<int>, vector<int>> ans1, ans2;
    ans1 = dijkstra(graph, n, 1);
    ans2 = dijkstra(rev, n, 1);

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(ans1.first[i] == INF || ans2.first[i] == INF){
            continue;
        }
        int tmp = (t - (ans1.first[i] + ans2.first[i])) * a[i-1];
        if(ans < tmp){
            ans = tmp;
        }
    }
    cout << ans << endl;

    return 0;
}