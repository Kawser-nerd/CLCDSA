#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#include <bitset>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define show(x) cout << #x << " = " << (x) << endl;
using namespace std;
using ll = long long;
using pii = pair<int,int>;
ll mod = 1e9+7;
struct edge{
    int to;
    int cost;
    edge(int a = 0, int b = 0):to(a),cost(b){}
};
vector<ll> dijkstra(const int s,const vector<vector<edge>>&g){
    int n = (int)g.size();
    vector<ll> dist(n+1,1L<<60);
    using ll_i = pair<ll,int>;
    priority_queue<ll_i,vector<ll_i>,greater<ll_i>>pq;
    dist[s] = 0;
    pq.push({dist[s], s});
    while(!pq.empty()){
        auto a = pq.top();
        pq.pop();
        int v = a.second;
        if(a.first > dist[v])continue;
        for(auto &x:g[v]){
            if(dist[x.to] > dist[v] + x.cost){
                dist[x.to] = dist[v] + x.cost;
                pq.push({dist[x.to], x.to});
            }
        }
    }
    return dist;
}
void dfs(int s, vector<bool>&used, vector<vector<edge>>&g,vector<ll>&dp){
    used[s] = true;
    for(auto &x:g[s]){
        if(!used[x.to]){
            dfs(x.to,used,g,dp);
        }
        dp[s] = (dp[s] + dp[x.to]) % mod;
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    int s, t;
    cin >> n >> m >> s >> t;
    vector<vector<edge>>g(n+1);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        int c;
        cin >> c;
        g[a].emplace_back(b,c);
        g[b].emplace_back(a,c);
    }
    auto dist = dijkstra(s, g);
    auto dist2 = dijkstra(t, g);
    vector<vector<edge>>graph(n+1), rgraph(n+1);
    rep(i,n){
        for(auto &x:g[i+1]){
            if(dist[i+1] + x.cost + dist2[x.to] == dist[t]){
                graph[i+1].emplace_back(x.to,x.cost);
                rgraph[x.to].emplace_back(i+1,x.cost);
            }
        }
    }
    vector<ll>dp(n+1),dp2(n+1);
    dp[s] = 1;
    dp2[t] = 1;
    vector<bool>used(n+1,false);
    dfs(t,used,rgraph,dp);
    fill(used.begin(),used.end(),false);
    dfs(s,used,graph,dp2);
    ll ans = 0;
    assert(dp[t] == dp2[s]);
    ans += dp[t] * dp2[s] % mod;
    ans %= mod;
    rep(i,n){
        if(dist[i+1] * 2 == dist[t]){
            ans -= dp[i+1] * dp2[i+1] % mod * dp[i+1] % mod * dp2[i+1] % mod;
            ans = (ans + mod) % mod;
        }
    }
    rep(i,n){
        for(auto &x:graph[i+1]){
            int from = i + 1;
            int to = x.to;
            int cost = x.cost;
            if(dist[from] * 2 < dist[t] and dist2[to] * 2 < dist[t] and (dist[from] + cost) * 2 > dist[t] and (dist2[to] + cost) * 2 > dist[t]){
                ans -= dp[from] * dp2[to] % mod * dp[from] % mod * dp2[to] % mod;
                ans = (ans + mod) % mod;
            }
        }
    }
    assert(ans>=0);
    cout << ans << endl;
}