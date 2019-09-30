// ???????? (???)

#include <stdio.h>
#include <string.h>
#define rep(i,a,n) for(int i=a; i<n; i++)
int dp[10][2], dp2[10][2];

int main() {
    char s[15];
    scanf("%s", s);

    int N = strlen(s);
    dp[0][0] = 1;
    rep(i,0,N) rep(j,0,2) {
        int lim = (j ? 9 : s[i] - '0');
        rep(x,0,lim+1) {
            dp[i+1][j||x<lim] += dp[i][j];
            dp2[i+1][j||x<lim] += dp2[i][j];
            if(x == 1) dp2[i+1][j||x<lim] += dp[i][j];
        }
    }
    int ans = dp2[N][0] + dp2[N][1];
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^