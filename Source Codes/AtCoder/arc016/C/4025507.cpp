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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> p(m, vector<int>(n));
    vector<int> c(m);
    rep(i, m){
        int k;
        cin >> k >> c[i];

        rep(j, k){
            int id;
            cin >> id;
            cin >> p[i][id-1];
        }
    }

    vector<double> dp(1 << n, 0);
    for(int s = (1 << n) - 2; s >= 0; s--){
        double mincost = INF;
        rep(i, m){
            double q = 0;
            rep(j, n){
                if((s >> j) % 2){
                    continue;
                }
                q += p[i][j];
            }
            double cost = c[i] * 100.0 / q;
            double prob = 0;
            rep(j, n){
                if((s >> j) % 2){
                    continue;
                }
                prob += (dp[s|(1<<j)] + cost) * p[i][j] / q;
            }
            mincost = min(mincost, prob);
        }
        dp[s] = mincost;
    }
    cout << fixed << setprecision(10) << dp[0] << endl;

    return 0;
}