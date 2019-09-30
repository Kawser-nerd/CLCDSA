#include <stdio.h>

const int mod = 1000000007;
long long int dp[3];

int main(){
  long long int n;
  scanf("%lld", &n);

  for(dp[0] = 1; n; n >>= 1){
    int z = n & 0x1;

    long long int tmp = (2*(dp[0^z] + dp[2]) + dp[1^z]) % mod;
    dp[1^z] = (dp[2] + 2*dp[1^z]) % mod;
    dp[2] = tmp;
  }
  printf("%lld\n", dp[0]);
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &n);
   ^