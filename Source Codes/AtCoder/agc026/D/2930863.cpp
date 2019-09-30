#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N = 105;
const int MOD = 1000000007;

int n,m,h[N],w[N];
LL dp[N][N];

int pow_(int x,int y) {///???? x?y??
    int ans = 1;
    if(y > 0) {
        while(y) {
            if(y % 2)ans = (LL)ans * x % MOD;
            x = (LL)x * x % MOD;
            y /= 2;
        }
    }
    return ans;
}

int main() {
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++) {
        scanf("%d",&h[i]);
        w[++ m] = h[i];
    }
    sort(w + 1,w + m + 1);///????
    m = unique(w + 1,w + m + 1) - w - 1;///??? m????????
    for(int i = 1;i <= n;i ++) {
        h[i] = lower_bound(w + 1,w + m + 1,h[i]) - w;
    }
    dp[0][0]=1;
    for(int i = 1;i <= n;i ++) {
        for(int j = h[i] + 1;j <= h[i - 1];j ++)
            (dp[i][0] += dp[i - 1][j] * 2 % MOD) %= MOD;
            
        (dp[i][0] += dp[i - 1][0] * 2 % MOD) %= MOD;///???????
        
        int d = pow_(2,w[h[i]] - w[h[i-1]]);
        for(int j = 1;j <= h[i];j ++) {
            dp[i][j] = dp[i - 1][j] * d % MOD;
        }
        
        for(int j = h[i - 1] + 1;j <= h[i];j ++) {///?????????
            if(j > 1)(dp[i][j] += dp[i - 1][0] * (pow_(2,w[j] - w[j - 1]) - 1) % MOD * 2 % MOD * pow_(2,w[h[i]] - w[j]) % MOD) %= MOD;
            else (dp[i][1] += dp[i - 1][0] * (pow_(2,w[1]) - 2) % MOD * pow_(2,w[h[i]] - w[1]) % MOD) %= MOD;///????????????????????????
        }
    }
    LL ans = 0;
    for(int i = 0;i <= m;i++)
        (ans += dp[n][i]) %= MOD;
    printf("%lld",ans);
    return 0;
}