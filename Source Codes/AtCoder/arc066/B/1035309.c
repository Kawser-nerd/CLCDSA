#include <stdio.h>

const int mod = 1000000007;
long long int dp[2][3];

int main(){
  int i, j;
  long long int n;
  scanf("%lld", &n);

  dp[0][0] = 1;
  for(i = 0; n; n >>= 1, i^=1){
    int z = (n & 0x1) << 1;

    dp[i^1][0^z] = dp[i][0^z];
    dp[i^1][1] = 2*(dp[i][0^z] + dp[i][1]) + dp[i][2^z];
    dp[i^1][2^z] = dp[i][1] + 2*dp[i][2^z];

    dp[i^1][0] %= mod;
    dp[i^1][1] %= mod;
    dp[i^1][2] %= mod;
  }
  printf("%lld\n", dp[i][0]);
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &n);
   ^