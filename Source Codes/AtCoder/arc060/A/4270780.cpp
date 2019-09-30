#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <utility>
#include <tuple>

using namespace std;
typedef long long ll;

int main()
{
    ll n, a;
    cin >> n >> a;
    vector<ll> x(n+1, 0);
    ll max_value = a;
    for (int i=1; i<=n; ++i){
        cin >> x[i];
        max_value = max(max_value, x[i]);
    }
    ll dp[n+1][n+1][max_value * n + 1];
    for (int i=0; i<=n; ++i){
        for (int j=0; j<=n; ++j){
            for (int k=0; k<=max_value * n; ++k){
                dp[i][j][k] = (i == 0 && j == 0 && k == 0) ? 1 : 0;
            }
        }
    }
    for (int i=0; i<=n; ++i){
        for (int j=0; j<=n; ++j){
            for (int k=0; k<=max_value * n; ++k){
                if(i >= 1 && k - x[i] >= 0){
                    dp[i][j][k] = dp[i-1][j-1][k-x[i]] + dp[i-1][j][k];
                }
                else if(i >= 1){
                    dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }
    }
    ll ans = 0;
    for (int i=1; i<=n; ++i){
        ans += dp[n][i][i * a];
    }
    cout << ans << endl;
    return 0;
}