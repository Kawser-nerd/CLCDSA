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

signed main(){
    int x, y, n;
    cin >> x >> y >> n;
    vector<int> t(n), h(n);
    rep(i, n) cin >> t[i] >> h[i];

    vector<vector<int>> dp(x+1, vector<int>(x+y+1, -1));
    dp[0][0] = 0;
    rep(i, n){
        for(int j = x-1; j >= 0; j--){
            for(int k = x + y; k >= 0; k--){
                if(k - t[i] < 0 || dp[j][k-t[i]] == -1){
                    continue;
                }
                dp[j+1][k] = max(dp[j+1][k], dp[j][k-t[i]] + h[i]);
            }
        }
    }
    int ans = 0;
    rep(i, x+1){
        rep(j, x+y+1){
            if(ans < dp[i][j]){
                ans = dp[i][j];
            }
        }
    }
    cout << ans << endl;

    return 0;
}