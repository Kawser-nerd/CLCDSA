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

typedef pair<int, int> P;
typedef pair<int, double> PD;

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
    int n;
    cin >> n;

    vector<double> x(n), y(n), t(n), r(n);
    rep(i, n) cin >> x[i] >> y[i] >> t[i] >> r[i];

    vector<vector<PD>> edge(n, vector<PD>());
    rep(i, n){
        rep(j, n){
            if(i == j){
                continue;
            }

            double sp = min(t[i], r[j]);
            double dist = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)) / sp;
            edge[i].emplace_back(j, dist);
        }
    }

    pair<vector<double>, vector<int>> result = dijkstra<double>(edge, n, 0);

    double ans = 0;
    sort(result.first.begin(), result.first.begin() + n);
    for(int i = 1; i < n; i++){
        ans = max(ans, result.first[i] + n - i - 1);
    }
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}