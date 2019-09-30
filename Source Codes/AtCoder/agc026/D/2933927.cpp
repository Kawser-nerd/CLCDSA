#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int MOD = (int)1e9 + 7;

int n,m,h[101],hnum[101],dh[101];
long long dp[101][101];

int pow_(long long x,int y) {///???? x?y??
    long long ans = 1;
    if(y > 0) {
        while(y) {
            if(y % 2)ans = ans * x % MOD;
            x = x * x % MOD;
            y /= 2;
        }
    }
    return ans;
}

int main() {
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++) {
        scanf("%d",&h[i]);
        dh[++ m] = h[i];
    }
    sort(dh + 1,dh + m + 1);///????
    m = unique(dh + 1,dh + m + 1) - dh - 1;///??? m????????
    for(int i = 1;i <= n;i ++) {
        hnum[i] = lower_bound(dh + 1,dh + m + 1,h[i]) - dh;
    }
    dp[0][0]=1;
    for(int i = 1;i <= n;i ++) {
        for(int j = hnum[i] + 1;j <= hnum[i - 1];j ++)
            (dp[i][0] += dp[i - 1][j] * 2 % MOD) %= MOD;

        (dp[i][0] += dp[i - 1][0] * 2 % MOD) %= MOD;///???????

        int d = pow_(2,h[i] - h[i - 1]);
        for(int j = 1;j <= min(hnum[i - 1],hnum[i]);j ++) {
            dp[i][j] = dp[i - 1][j] * d % MOD;
        }
        for(int j = hnum[i - 1] + 1;j <= hnum[i];j ++) {///?????????
            if(j > 1)(dp[i][j] += dp[i - 1][0] * (pow_(2,dh[j] - dh[j - 1]) - 1) % MOD * 2 % MOD * pow_(2,h[i] - dh[j]) % MOD) %= MOD;
            else (dp[i][1] += dp[i - 1][0] * (pow_(2,dh[1]) - 2) % MOD * pow_(2,h[i] - dh[1]) % MOD) %= MOD;///??????????????????????????
        }
    }
    long long ans = 0;
    for(int i = 0;i <= hnum[n];i++)
        (ans += dp[n][i]) %= MOD;
    printf("%lld",ans);
    return 0;
}