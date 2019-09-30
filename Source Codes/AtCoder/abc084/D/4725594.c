#include <stdio.h>

int main(void){
  int Q;
  scanf("%d",&Q);

  int is_prime[100001];
  int dp[100001];

  for(int i = 2;i <= 100000;i++){
    is_prime[i] = 1;
    dp[i] = 0;
  }
  for(int i = 2;i <= 100000;i++){
    if(is_prime[i]){
      for(int j = 2*i;j <= 100000;j += i){
        is_prime[j] = 0;
      }
    }
  }

  for(int i = 3;i <= 100000;i += 2){
    if(is_prime[i] && is_prime[(i+1)/2]){
      dp[i] = 1;
    }
  }

  for(int i = 1;i <= 100000;i++){
    dp[i] += dp[i-1];
  }

  int l,r;
  for(int i = 0;i < Q;i++){
    scanf("%d%d",&l,&r);
    printf("%d\n",dp[r]-dp[l-1]);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&Q);
   ^
./Main.c:34:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&l,&r);
     ^