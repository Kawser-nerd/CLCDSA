#include <stdio.h>
#include <string.h>

int E, R, N;
int value[11000];
int dp[100][100];

int min(int x, int y)
{
    return x<y?x:y;
}

int max(int x, int y)
{
    return x>y?x:y;
}

int main()
{
    int T, Tcnt=0;
    for(scanf("%d", &T); T; T--) {
        int i, ans;
        scanf("%d%d%d", &E, &R, &N);
        for(i=0; i<N; i++) {
            scanf("%d", value+i);
        }
        memset(dp, 0x80, sizeof(dp));
        dp[0][E]=0;
        for(i=1; i<=N; i++) {
            int j;
            for(j=min(R,E); j<=E; j++) {
                int k;
                for(k=max(j-R,0); k<=E; k++) {
                    dp[i][j] = max(dp[i][j], dp[i-1][k]+(k-max(j-R,0))*value[i-1]);
                }
            }
        }
        for(i=ans=0; i<=E; i++) {
            ans = max(ans, dp[N][i]);
        }
        printf("Case #%d: %d\n", ++Tcnt, ans);
    }
    return 0;
}
