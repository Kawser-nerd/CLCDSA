#include <stdio.h>
#include <string.h>
#define mod 1000000007

int main(void){
  char S[100005];
  scanf("%s",S);

  long long dp[strlen(S)+1][3];

  long long c = 1;
  dp[0][0] = 0;
  dp[0][1] = 0;
  dp[0][2] = 0;
  for(int i = 0;i < strlen(S);i++){
    for(int j = 0;j < 3;j++) dp[i+1][j] = dp[i][j];
    if(S[i] == 'A') dp[i+1][0] = (dp[i+1][0]+c)%mod;
    if(S[i] == 'B') dp[i+1][1] = (dp[i+1][1]+dp[i][0])%mod;
    if(S[i] == 'C') dp[i+1][2] = (dp[i+1][2]+dp[i][1])%mod;
    if(S[i] == '?'){
      dp[i+1][0] = (dp[i+1][0]*3+c)%mod;
      dp[i+1][1] = (dp[i+1][1]*3+dp[i][0])%mod;
      dp[i+1][2] = (dp[i+1][2]*3+dp[i][1])%mod;
      c = (c*3)%mod;
    }
  }
   
  printf("%lld\n",dp[strlen(S)][2]);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",S);
   ^