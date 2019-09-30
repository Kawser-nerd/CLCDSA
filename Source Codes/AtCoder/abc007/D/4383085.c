#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Max_digit 20
// DP????
long dp[Max_digit][2][2];  // dp[][0]?????, dp[][1]?????
// ?DP
long digitDP (char num[]) {
    // ???
    memset(dp, 0, sizeof(dp));
    // ???
    dp[0][0][0] = 1; dp[0][0][1] = 0;
    dp[0][1][0] = 0; dp[0][1][1] = 0;
    int N = strlen(num); // ??
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                int x = j ? 9:(num[i] - '0'); // 1???9
                //printf("i, %d, j, %d, k %d, x %d\n", i,  j, k, x );
                for (int d = 0; d <= x; d++) {
                    dp[i+1][j || d<x][k || d==4 || d==9] += dp[i][j][k];
                    //printf("dp[1][1][1] %ld\n", dp[1][1][1] );
                }
            }
        }
    }
    long ans = dp[N][1][1] + dp[N][0][1];;
    //printf("dp[N][1][1] + dp[N][0][1] %ld\n", ans );
    return ans;
}


int main(int argc, char const *argv[]) {
    // ??
    long a,b;
    char A[Max_digit+1], B[Max_digit+1];
    scanf("%ld %ld", &a, &b);
    // ??????
    a = a-1;
    snprintf(A, Max_digit+1, "%ld", a);
    snprintf(B, Max_digit+1, "%ld", b);
    // ??
    long ans = digitDP(B) - digitDP(A);
    printf("%ld\n", ans );
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:37:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld", &a, &b);
     ^