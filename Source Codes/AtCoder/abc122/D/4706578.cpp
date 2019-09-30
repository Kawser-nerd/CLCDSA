#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll MOD = 1000000007;

int main(){
    int N;
    cin >> N;
    vector<vector<vector<vector<ll>>>> dp(N+1,vector<vector<vector<ll>>>(4,vector<vector<ll>>(4, vector<ll>(4,0))));
    int A=0,C=1,G=2,T=3;
    // AGC / GAC / ACG / AXGC / AGXC ???
    dp[0][3][3][3] = 1;
    for (int len = 0; len < N; len++){
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                for (int k = 0; k < 4; k++){
                    if (dp[len][i][j][k] == 0) continue;
                    
                    for (int a = 0; a < 4; a++){
                        if (a == C && i == G && j == A) continue;
                        if (a == C && i == A && j == G) continue;
                        if (a == G && i == C && j == A) continue;
                        if (a == C && i == G && k == A) continue;
                        if (a == C && j == G && k == A) continue;
                        
                        dp[len + 1][a][i][j] += dp[len][i][j][k];
                        dp[len + 1][a][i][j] %= MOD;
                    }
                }
            }
        }
    }
    
    ll ans = 0;
    
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            for (int k = 0; k < 4; k++){
                ans += dp[N][i][j][k];
                ans %= MOD;
            }
        }
    }
    
    cout << ans << endl;
}