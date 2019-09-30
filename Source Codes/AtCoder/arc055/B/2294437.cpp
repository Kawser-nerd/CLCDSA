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

const int inf = 1e15;

using namespace std;

signed main(){
    int n, k;
    cin >> n >> k;

    vector<vector<vector<double>>> dp(n+1, vector<vector<double>>(k+1, vector<double>(2)));
    for(int i = 1; i <= k; i++){
        dp[n][i][1] = 1;
    }
    for(int i = n-1; i >= 0; i--){
        for(int j = k; j >= 0; j--){
            for(int b = 0; b <= 1; b++){
                if(i < j){
                    continue;
                }
                double p = 1.0 / (i + 1.0);
                if(j == k){
                    dp[i][j][b] = p * dp[i+1][j][0] + (1.0 - p) * dp[i+1][j][b];
                    continue;
                }
                dp[i][j][b] = p * max(dp[i+1][j+1][1], dp[i+1][j][0]) + (1.0 - p) * dp[i+1][j][b];
            }
        }
    }

    cout << fixed << setprecision(7) << dp[0][0][0] << endl;
    return 0;
}