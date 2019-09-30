#include <stdio.h>

typedef long long int ll;

int mod = 1000000007;

int dp[1001][1001];

int main(){
  int i, j, k, n, ans;

  for(i=2;i<=1000;i++){
    if(dp[i][0]) continue;
    for(j=i;j<=1000;j+=i) dp[j][0]=1;
    for(k=i;k<=1000;k*=i){
      for(j=k;j<=1000;j+=k){
        dp[j][i]++;
      }
    }
  }

  scanf("%d", &n);

  for(j=2;j<=n;j++){
    for(i=j;i<n;i++){
      dp[n][j] += dp[i][j];
    }
  }

  ans = 1;
  for(j=2;j<=n;j++){
    ans = (ll) ans * (dp[n][j]+1) % mod;
  }

  printf("%d\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^