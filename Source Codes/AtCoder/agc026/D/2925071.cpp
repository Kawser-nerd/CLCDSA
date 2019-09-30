#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N = 105;
const int MOD = 1000000007;

int n,f[N][N],h[N],w[N],m;

int ksm(int x,int y) {
    if(y < 0)return 1;
    int ans = 1;
    while(y) {
        if(y & 1)ans = (LL)ans * x % MOD;
        x = (LL)x * x % MOD;
        y /= 2;
    }
    return ans;
}

int main() {
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++) {
        scanf("%d",&h[i]);
        w[++ m] = h[i];
    }
    sort(w + 1,w + m + 1);
    m = unique(w + 1,w + m + 1) - w - 1;
    for(int i = 1;i <= n;i ++) {
        h[i] = lower_bound(w + 1,w + m + 1,h[i]) - w;
    }
    f[0][0]=1;
    for(int i = 1;i <= n;i ++) {
        for(int j = h[i] + 1;j <= h[i-1];j ++)
            (f[i][0] += f[i - 1][j] * 2 % MOD) %= MOD;
        (f[i][0] += f[i - 1][0] * 2 % MOD) %= MOD;
        for(int j = 1;j <= h[i];j ++) {
            f[i][j]=(LL)f[i - 1][j] * ksm(2,w[h[i]] - w[h[i-1]]) % MOD;
            if(h[i - 1] >= j)continue;
            if(j > 1)(f[i][j] += (LL)f[i - 1][0] * (ksm(2,w[j] - w[j - 1]) - 1) % MOD * 2 % MOD * ksm(2,w[h[i]] - w[j]) % MOD) %= MOD;
            else (f[i][j] += (LL)f[i - 1][0] * (ksm(2,w[j]) - 2) % MOD * ksm(2,w[h[i]] - w[j]) % MOD) %= MOD;
        }
    }
    int ans = 0;
    for(int i = 0;i <= m;i++)
        (ans += f[n][i]) %= MOD;
    printf("%d",ans);
    return 0;
}