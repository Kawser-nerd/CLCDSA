#include <stdio.h>
#include <string.h>

double dp[20][20]; // dp[X][w]
double p[20];
int N, K;
double res;

double max(double a, double b){return a>b?a:b;}

void dfs(int c, int u){
    int w;
    if (u==K) {
        res = max(res, dp[K][K/2]);
        return;
    }
    if (c==N) return;
    // no use cur
    dfs(c+1, u);
    // use cur
    memset(dp[u+1],0,sizeof(dp[u+1]));
    // dp here
    for (w=0;w<=u;w++){
        dp[u+1][w+1] += dp[u][w]*p[c];
        dp[u+1][w] += dp[u][w] * (1-p[c]);
    }
    dfs(c+1, u+1);
}


int main(){
    int cas, T;
    int i,j,k;
    scanf("%d", &T);
    for (cas=1;cas<=T;cas++){
        scanf("%d %d", &N, &K);
        for (i=0;i<N;i++) scanf("%lf", &p[i]);
        memset(dp,0,sizeof(dp));
        res = 0.0;
        dp[0][0]=1.0;
        dfs(0, 0);
        printf("Case #%d: %.10lf\n", cas, res);
    }
    return 0;
}
