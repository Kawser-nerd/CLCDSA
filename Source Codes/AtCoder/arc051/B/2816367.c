#include <stdio.h>

int main() {
  int k;
  scanf("%d", &k);

  int dp[45] = {};

  dp[0] = 1;
  dp[1] = 2;

  for(int i = 2; i < 45; i++){
    dp[i] = dp[i-1] + dp[i-2];
  }

  // for(int i = 0; i < 45; i++){
    printf("%d %d\n", dp[k], dp[k-1]);
  // }

} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &k);
   ^