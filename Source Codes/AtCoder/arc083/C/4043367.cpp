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

int n;
vector<vector<int>> edge;
vector<int> x;
vector<P> best;

bool dfs(int v){
    vector<P> vp;
    for(int u : edge[v]){
        if(not dfs(u)){
            return false;
        }
        vp.push_back(best[u]);
    }

    vector<vector<int>> dp(SZ(vp) + 1, vector<int>(5001, INF));
    dp[0][0] = 0;
    rep(i, SZ(vp)){
        rep(j, 5000){
            if(j + vp[i].first <= 5000){
                dp[i+1][j+vp[i].first] = min(dp[i+1][j+vp[i].first], dp[i][j] + vp[i].second);
            }
            if(j + vp[i].second <= 5000){
                dp[i+1][j+vp[i].second] = min(dp[i+1][j+vp[i].second], dp[i][j] + vp[i].first);
            }
        }
    }

    int ans = -1;
    for(int i = 0; i <= x[v]; i++){
        if(dp[SZ(vp)][i] < INF){
            ans = dp[SZ(vp)][i];
        }
    }
    best[v] = {x[v], ans};

    return ans != -1 ;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    edge = vector<vector<int>>(n + 1, vector<int>());
    for(int i = 2; i <= n; i++){
        int p;
        cin >> p;
        edge[p].push_back(i);
    }
    x = vector<int>(n + 1);
    rep(i, n) cin >> x[i+1];

    best = vector<P>(n + 1);
    cout << (dfs(1) ? "POSSIBLE" : "IMPOSSIBLE") << endl;

    return 0;
}