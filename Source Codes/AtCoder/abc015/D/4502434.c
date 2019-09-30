#include <stdio.h>

int max(int a,int b){
  if(a > b){
    return a;
  }
  return b;
}

int main(void){
  int W,N,K;
  scanf("%d%d%d",&W,&N,&K);

  int A[N],B[N];
  for(int i = 0;i < N;i++){
    scanf("%d%d",&A[i],&B[i]);
  }

  int dp[W+2][K+2][N+2];
  for(int i = 0;i <= W;i++){
    for(int j = 0;j <= K;j++){
      for(int k = 0;k <= N;k++)
        dp[i][j][k] = 0;
    }
  }
  for(int i = 1;i <= W;i++){
    for(int j = 1;j <= K;j++){
      for(int k = 1;k <= N;k++){
        if(i-A[k-1] >= 0) 
          dp[i][j][k] = max(dp[i][j][k-1],dp[i-A[k-1]][j-1][k-1]+B[k-1]);
        else
          dp[i][j][k] = dp[i][j][k-1];
      }
    }
  }

  printf("%d\n",dp[W][K][N]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&W,&N,&K);
   ^
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&A[i],&B[i]);
     ^