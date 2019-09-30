#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX(a,b) ((a)>(b)?(a):(b))


int main(void) {
   int W,N,K;
   scanf("%d", &W);
   scanf("%d %d", &N, &K);
   int L[N+1][2];
   for (int i = 0; i < N; i++) {
      scanf("%d %d",&L[i][0],&L[i][1]);
   }
   int dp[W+2][N+2][K+2];
   for (int w = 0; w < W+2; w++) {
      for (int i = 0; i < N + 2; i++) {
         for (int k = 0; k < K + 2; k++) {
            dp[w][i][k] = 0;
         }
      }
   }

   for (int w = W; w >= 0; w--) {
      for (int i = 0; i < N; i++) {
         for (int cnt = 0; cnt < K+1; cnt++) {
            if (w - L[i][0] >= 0 && cnt+1 <= K) {
               dp[w-L[i][0]][i+1][cnt+1] = MAX(dp[w-L[i][0]][i+1][cnt+1],L[i][1]+dp[w][i][cnt]);
            }
            dp[w][i+1][cnt] = MAX(dp[w][i+1][cnt],dp[w][i][cnt]);

         }
      }
   }
   int ans = 0;
   for (int w = 0; w < W + 1; w++) {
      for (int cnt = 0; cnt < K + 1; cnt++) {
         ans = MAX(dp[w][N][cnt], ans);
      }
   }
   printf("%d\n",ans);


} ./Main.c: In function ‘main’:
./Main.c:10:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &W);
    ^
./Main.c:11:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d %d", &N, &K);
    ^
./Main.c:14:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d %d",&L[i][0],&L[i][1]);
       ^