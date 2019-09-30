#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,q;
int dp[502][502];
int main() {
    int a,b;
    scanf("%d%d%d",&n,&m,&q);
    for(int i = 0;i < m;i ++) {
        scanf("%d%d",&a,&b);
        dp[a][b] ++;
    }
    for(int j = 1;j < n;j ++) {
        for(int i = 1;i + j <= n;i ++) {
            int k = i + j;
            dp[i][k] += dp[i + 1][k] + dp[i][k - 1];
            if(j > 1)dp[i][k] -= dp[i + 1][k - 1];
        }
    }
    for(int i = 0;i < q;i ++) {
        scanf("%d%d",&a,&b);
        printf("%d\n",dp[a][b]);
    }
    return 0;
}