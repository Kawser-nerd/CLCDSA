#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define show(x) cout << #x << " = " << x << endl;
using namespace std;
using ll = long long;
using pii = pair<int,int>;
int dp[2005][2005];//?,?
int gyaku[2][2005];
int rui1[4005][2005];//?
int rui2[4005][2005];//?
int main(){
    int n;
    cin >> n;
    vector<bool>c(2*n);
    vector<int>a(2*n);
    rep(i,2*n){
        char k;
        cin >> k >> a[i];
        if(k == 'B'){
            c[i] = true;
        }else{
            c[i] = false;
        }
        gyaku[c[i]][a[i]] = i;
    }
    rep(i,2*n){
        for(int j = 1; j <= n; j++){
            if(a[i] == j){
                if(c[i]){
                    rui1[i][j] = rui1[i][j-1] + 1;
                }else{
                    rui2[i][j] = rui2[i][j-1] + 1;
                }
            }else{
                rui1[i][j] = rui1[i][j-1];
                rui2[i][j] = rui2[i][j-1];
            }
        }
    }
    rep(i,2*n){
        for(int j = 1; j <= n; j++){
            rui1[i+1][j]+=rui1[i][j];
            rui2[i+1][j]+=rui2[i][j];
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            int x;
            //calc dp[i][j]
            int cnt;
            dp[i][j] = INT_MAX;
            if(i==0 and j== 0)dp[i][j] = 0;
            //dp[i-1][j];?
            if(i){
                x = gyaku[1][i];
                cnt = rui1[2*n-1][i-1] - rui1[x][i-1] + rui2[2*n-1][j] - rui2[x][j];
                dp[i][j] = min(dp[i-1][j]+cnt,dp[i][j]);
            }
            if(j){
                x = gyaku[0][j];
                cnt = rui1[2*n-1][i] - rui1[x][i] + rui2[2*n-1][j-1] - rui2[x][j-1];
                dp[i][j] = min(dp[i][j-1]+cnt,dp[i][j]);
            }
        }
    }
    cout << dp[n][n] << endl;
}