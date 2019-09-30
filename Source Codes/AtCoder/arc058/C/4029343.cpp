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

    int n, x, y, z;
    cin >> n >> x >> y >> z;
    int sum = x + y + z - 1;
    int mask = (1 << sum) - 1;

    vector<vector<int>> dp(n + 1, vector<int>(1 << sum));
    dp[0][0] = 1;
    rep(i, n){
        rep(s, 1 << sum){
            for(int j = 1; j <= 10; j++){
                int t = ((s << j) | (1 << (j - 1)));
                if((t >> (z - 1)) % 2 && (t >> (y + z - 1)) % 2 && (t >> sum) % 2){
                    continue;
                }
                dp[i+1][t&mask] += dp[i][s];
                dp[i+1][t&mask] %= MOD;
            }
        }
    }

    int all = 1;
    rep(i, n){
        all *= 10;
        all %= MOD;
    }
    int ans = 0;
    rep(s, 1 << sum){
        ans += dp[n][s];
        ans %= MOD;
    }

    cout << ((all + MOD) - ans) % MOD << endl;

    return 0;
}