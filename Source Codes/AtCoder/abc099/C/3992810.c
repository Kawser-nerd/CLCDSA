#include <stdio.h>
#include <math.h>

#define INF 1 << 30

int dp[100001];

int main()
{
    int N;
    int i, j;

    scanf("%d", &N);
    for(i = 0; i <= N; i++) dp[i] = INF;

    for(i = 0; i <= N; i++) {
        if(0 <= i && i < 6) {
            dp[i] = i;
            continue;
        }
        for(j = 0; pow(6, j) <= i; j++) {
            if(dp[i-(int)pow(6, j)]+1 < dp[i]) {
                dp[i] = dp[i-(int)pow(6, j)]+1;
            }
        }
        for(j = 0; pow(9, j) <= i; j++) {
            if(dp[i-(int)pow(9, j)]+1 < dp[i]) {
                dp[i] = dp[i-(int)pow(9, j)]+1;
            }
        }
    }
    printf("%d\n", dp[N]);   

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^