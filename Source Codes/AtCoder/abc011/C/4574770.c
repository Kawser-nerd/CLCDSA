#include <stdio.h>

int ng[3];

int min(int a,int b){
  if(a < b){
    return a;
  }
  return b;
}

int check(int N){
  if(N != ng[0] && N != ng[1] && N != ng[2])
    return 0;
  return 1;
}

int main(void){
  int N;
  scanf("%d",&N);

  for(int i = 0;i < 3;i++) scanf("%d",&ng[i]);

  int dp[301];
  for(int i = 0;i < 301;i++) dp[i] = 1e9;

  dp[N] = 0;
  for(int i = N;i >= 0;i--){
    if(check(i)) continue;
    for(int j = 1;j <= 3;j++){
      if(i-j >= 0)
        dp[i-j] = min(dp[i]+1,dp[i-j]);
    }
  }

  if(dp[0]<= 100) printf("YES\n");
  else printf("NO\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:22:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 0;i < 3;i++) scanf("%d",&ng[i]);
                            ^