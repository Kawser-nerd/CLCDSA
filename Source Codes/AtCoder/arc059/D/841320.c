#include <stdio.h>
#include <string.h>

typedef long long ll;
#define MOD 1000000007LL
ll dp[2][5001];
int main(void){
  int N, i, j;
  char buf[5001];
  scanf("%d%s", &N, buf);
  dp[0][0] = 1;
  for(i=0;i<N;++i){
    int w = i&1;
    dp[1-w][0] = dp[1-w][1] = dp[w][0];
    for(j=1;j<=N;++j){
      dp[1-w][j-1] = (dp[1-w][j-1]+dp[w][j]*2)%MOD;
      dp[1-w][j+1] = dp[w][j];
    }
  }
  printf("%lld\n", dp[N&1][strlen(buf)]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%s", &N, buf);
   ^