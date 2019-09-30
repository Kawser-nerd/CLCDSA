#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int n, m, y, z;
    cin >> n >> m >> y >> z;
    map<char, int> color;
    vector<int> score(m);
    rep(i, m){
        char c;
        int p;
        cin >> c >> p;
        color.emplace(c, i);
        score[i] = p;
    }
    vector<char> b(n);
    rep(i, n) cin >> b[i];

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(1 << m, -INF)));
    rep(i, m){
        dp[0][m][0] = 0;
    }
    for(int i = 0; i < n; i++){
        rep(j, m+1){
            rep(k, (1 << m)){
                if(dp[i][j][k] == -INF){
                    continue;
                }
                int cc = color[b[i]];
                int s = dp[i][j][k] + score[cc];
                if(j == cc){
                    s += y;
                }
                if( (k != (1 << m) - 1) && ((k | (1 << cc)) == (1 << m) - 1)){
                    s += z;
                }
                dp[i+1][cc][k | (1 << cc)] = max(dp[i+1][cc][k | (1 << cc)], s);
                dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
            }
        }
    }

    int ans = 0;
    rep(j, m){
        rep(k, (1 << m)){
            if(ans < dp[n][j][k]){
                ans = dp[n][j][k];
            }
        }
    }
    cout << ans << endl;
    return 0;
}