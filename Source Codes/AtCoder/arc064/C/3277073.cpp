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

using namespace std;

typedef pair<int, double> P;

const int INF = 1e15;
const int MOD = 1e9+7;

pair<vector<double>, vector<int>> dijkstra(const vector<vector<P>>& graph, int n, int s){
    vector<double> d(n+1, INF);
    d[s] = 0;

    vector<int> p(n+1, -1);
    p[s] =  s;

    priority_queue<P, vector<pair<double, int>>, greater<pair<double, int>>> que;
    que.emplace(0.0, s);

    while(!que.empty()){
        double w = que.top().first;
        int to = que.top().second;
        que.pop();

        if(d[to] < w){
            continue;
        }

        rep(i, (int)graph[to].size()){
            int from = graph[to][i].first;
            double nw = w + graph[to][i].second;
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
    double xs, ys, xt, yt;
    int n;
    cin >> xs >> ys >> xt >> yt >> n;

    vector<double> x(n), y(n), r(n);
    rep(i, n) cin >> x[i] >> y[i] >> r[i];

    vector<vector<P>> edge(n+2, vector<P>());
    double d = max(0.0, sqrt(pow(xs - xt, 2) + pow(ys - yt, 2)));
    edge[0].emplace_back(n+1, d);
    edge[n+1].emplace_back(0, d);

    rep(i, n){
        double ds = max(0.0, sqrt(pow(xs - x[i], 2) + pow(ys - y[i], 2)) - r[i]);
        edge[0].emplace_back(i+1, ds);
        edge[i+1].emplace_back(0, ds);

        double dt = max(0.0, sqrt(pow(xt - x[i], 2) + pow(yt - y[i], 2)) - r[i]);
        edge[n+1].emplace_back(i+1, dt);
        edge[i+1].emplace_back(n+1, dt);

        for(int j = i + 1; j < n; j++){
            double d = max(0.0, sqrt(pow(x[j] - x[i], 2) + pow(y[j] - y[i], 2)) - r[i] - r[j]);
            edge[i+1].emplace_back(j+1, d);
            edge[j+1].emplace_back(i+1, d);
        }
    }

    pair<vector<double>, vector<int>> ans = dijkstra(edge, n+2, 0);
    cout << fixed << setprecision(10) << ans.first[n+1] << endl;

    return 0;
}