#include <stdio.h>
#include <string.h>
int main(){
  char s[100010];
  long long int dp[100010][4];
  scanf("%s",s);
  int i,j;
  int N = strlen(s),mod = 1000000007;
  for(i = N; i >= 0; --i){
    for(j = 3; j >= 0; --j){
      if(i == N){
        dp[i][j] = (j == 3 ? 1 : 0);
      }else{
        dp[i][j] = dp[i+1][j] * (s[i] == '?' ? 3ll : 1ll);
        if(j < 3 && (s[i] == '?' || s[i] == 'A'+j)){
          dp[i][j] += dp[i+1][j+1];
        }
        dp[i][j] %= mod;
      }
    }
  }
  printf("%lld\n",dp[0][0]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^