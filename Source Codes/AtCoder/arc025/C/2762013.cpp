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
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

pair<vector<int>, vector<int>> dijkstra(const vector<vector<P>>& graph, int n, int s){
    vector<int> d(n+1, INF);
    d[s] = 0;

    vector<int> p(n+1, -1);
    p[s] =  s;

    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(0, s);

    while(!que.empty()){
        int w = que.top().first;
        int to = que.top().second;
        que.pop();

        if(d[to] < w){
            continue;
        }

        rep(i, (int)graph[to].size()){
            int from = graph[to][i].first;
            int nw = w + graph[to][i].second;
            if(nw < d[from]){
                d[from] = nw;
                p[from] = to;
                que.emplace(nw, from);
            }
        }
    }
    return make_pair(d, p);
}

signed main(){
    int n, m, R, T;
    cin >> n >> m >> R >> T;

    vector<vector<P>> graph(n+1, vector<P>());
    rep(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        pair<vector<int>, vector<int>> res = dijkstra(graph, n, i);
        vector<int> dist = res.first;
        sort(dist.begin(), dist.end());

        for(int j = 1; j < n; j++){
            int l = 0;
            int r = n;
            while(r - l > 1){
                int m = (l + r) / 2;
                if(dist[j] * T > dist[m] * R){
                    l = m;
                }else{
                    r = m;
                }
            }
            if(j <= l){
                l--;
            }
            ans += l;
        }
    }
    cout << ans << endl;

    return 0;
}