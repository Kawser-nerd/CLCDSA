#include <stdio.h>
#define INF 1 << 30

int min(int a,int b){
  if(a < b){
    return a;
  }
  return b;
}

int main(void){
  int N,Ma,Mb;
  scanf("%d%d%d",&N,&Ma,&Mb);

  int a[N],b[N],c[N];
  for(int i = 0;i < N;i++){
    scanf("%d%d%d",&a[i],&b[i],&c[i]);
  }

  int dp[N+1][401][401];
  for(int i = 0;i <= N;i++){
    for(int j = 0;j <= 400;j++){
      for(int k = 0;k <= 400;k++){
        dp[i][j][k] = INF;
      }
    }
  }
  dp[0][0][0] = 0;

  int ca = 0,cb = 0;
  for(int i = 0;i < N;i++){
    for(int j = 0;j <= 400;j++){
      for(int k = 0;k <= 400;k++){
        if(dp[i][j][k] == INF) continue;
        dp[i+1][j][k] = min(dp[i+1][j][k],dp[i][j][k]);
        dp[i+1][j+a[i]][k+b[i]] = min(dp[i+1][j+a[i]][k+b[i]],dp[i][j][k]+c[i]);
      }
    }
  }

  int ans = INF;
  for(int i = 1;i <= 400;i++){
    for(int j = 1;j <= 400;j++){
      if(i*Mb == j*Ma){
        ans = min(ans,dp[N][i][j]);
      }
    }
  }

  if(ans == INF) printf("-1\n");
  else printf("%d\n",ans);
  
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&N,&Ma,&Mb);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a[i],&b[i],&c[i]);
     ^