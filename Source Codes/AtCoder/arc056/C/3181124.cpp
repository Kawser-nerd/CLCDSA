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

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> r(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> r[i][j];

    vector<int> gr(1 << n);
    for(int s = 1; s < (1 << n); s++){
        rep(i, n){
            if((s >> i) % 2 == 0){
                continue;
            }
            rep(j, i){
                if((s >> j) % 2 == 0){
                    continue;
                }
                gr[s] += r[i][j];
            }
        }
    }

    vector<int> dp(1 << n);
    dp[0] = 0;
    for(int s = 1; s < (1 << n); s++){
        for(int t = ((1 << n) - 1) & s; t > 0; t = (t - 1) & s){
            dp[s] = max(dp[s], dp[s^t] + k - gr[s] + gr[s^t] + gr[t]);
        }
    }
    cout << dp[(1 << n) - 1] << endl;

    return 0;
}