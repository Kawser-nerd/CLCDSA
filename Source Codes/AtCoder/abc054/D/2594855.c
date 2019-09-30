#include<stdio.h>

int main(){
  int n,ma,mb,a[40],b[40],c[40],dp[41][401][401]={},i,j,k,min=4000000,nn;
  scanf("%d %d %d",&n,&ma,&mb);
  for(i=0;i<=40;i++)
    for(j=0;j<=400;j++)
      for(k=0;k<=400;k++)
        dp[i][j][k]=40000;
  dp[0][0][0]=0;
  //for(i=0;i<=n;i++)
    //printf("%d\n",dp[i][400][400]);
  for(i=0;i<n;i++){
    scanf("%d %d %d",&a[i],&b[i],&c[i]);
    for(j=0;j<=400;j++)
      for(k=0;k<=400;k++){
        if(dp[i][j][k]<dp[i+1][j][k])
          dp[i+1][j][k]=dp[i][j][k];
        if(j>=a[i]&&k>=b[i]&&dp[i+1][j][k]>dp[i][j-a[i]][k-b[i]]+c[i])
          dp[i+1][j][k]=dp[i][j-a[i]][k-b[i]]+c[i];
      }
  }
  for(i=1;i*ma<=400&&i*mb<=400;i++){
    if(min>dp[n][i*ma][i*mb])
      min=dp[n][i*ma][i*mb];
    //printf("%d\n",dp[n][i*ma][i*mb]);
  }
  if(min<40000)
    printf("%d\n",min);
  else
    printf("-1\n");
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&n,&ma,&mb);
   ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&a[i],&b[i],&c[i]);
     ^