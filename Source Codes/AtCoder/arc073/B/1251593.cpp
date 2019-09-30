#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<vector>
using namespace std;
using uint = unsigned int;
using ll = long long;
const int M = 1e9 + 7;
const ll MLL = 1e18L + 9;
#pragma unused(M)
#pragma unused(MLL)
#ifdef LOCAL
#include"rprint.hpp"
#else
template <class... T> void printl(T&&...){ }
template <class... T> void printc(T&&...){ }
template <class... T> void prints(T&&...){ }
template <class... T> void printd(T&&...){ }
#endif

int main(){
    int n, w;
    cin >> n >> w;
    int w1, v1;
    cin >> w1 >> v1;
    vector<int> ws = {w1}, vs = {v1};
    for(int i=1;i<n;i++){
        int w, v;
        cin >> w >> v;
        ws.push_back(w);
        vs.push_back(v);
    }
    if(false && w1 < 1000){
        vector<vector<int>> dp(n + 1, vector<int> (w + 1));
        for(int i=0;i<n;i++){
            for(int j=0;j<=w;j++){
                // dp[i + 1][j + ws[i]] = max({dp[i][j + ws[i]], dp[i + 1][j + ws[i]], dp[i][j] + vs[i]});
                dp[i + 1][j] = max({dp[i][j], dp[i + 1][j], j - ws[i] >= 0 ? dp[i][j - ws[i]] + vs[i] : 0});
            }
        }
        int ans = 0;
        for(int i=0;i<=w;i++){
            ans = max(ans, dp[n][i]);
        }
        // prints(dp);
        cout << ans << '\n';
    }else{
        int rem = w % w1;
        printd(rem);
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (n + 1, vector<int> (3 * n + 1)));
        for(int i=0;i<n;i++){
            for(int j=1;j<=n;j++){
                for(int k=0;k<=3 * n;k++){
                    // dp[i + 1][j][k] = 
                    dp[i + 1][j][k] = max({
                        dp[i][j][k],
                        dp[i + 1][j][k],
                        k - (ws[i] - w1) >= 0 ? dp[i][j - 1][k - (ws[i] - w1)] + vs[i] : 0
                    });
                }
            }
        }
        prints(dp);
        int ans = 0;
        for(int j=0;j<=n;j++){
            for(int k=0;k<=3 * n;k++){
                if(j * w1 + k > w){ continue; }
                ans = max(ans, dp[n][j][k]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}