#include<stdio.h>
int MIN(int a,int b){return a<b?a:b;}
int main(){
  int n,m,r,i,j,k,d[210][210],dp[300][10],g[20];
  scanf("%d %d %d",&n,&m,&r);
  for(i=0;i<r;i++)scanf("%d",&g[i]);
  for(i=0;i<r;i++)g[i]--;
  for(i=0;i<n*n;i++)d[i/n][i%n]=i%n==i/n?0:1e9;
  while(m--){
    scanf("%d %d %d",&i,&j,&k);
    d[i-1][j-1]=d[j-1][i-1]=k;
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++)d[j][k]=MIN(d[j][k],d[j][i]+d[i][k]);
    }
  }
  /*for(i=0;i<n;i++){
    for(j=0;j<n;j++)printf("%2d ",d[i][j]);printf("\n");
    }//*/
  for(i=0;i<(1<<r);i++){
    for(j=0;j<r;j++)dp[i][j]=1e9;
  }
  for(i=0;i<r;i++)dp[1<<i][i]=0;
  for(i=0;i<(1<<r);i++){
    for(j=0;j<r;j++){
      if(i&(1<<j)==0)continue;
      for(k=0;k<r;k++)dp[i|(1<<k)][k]=MIN(dp[i|(1<<k)][k],dp[i][j]+d[g[j]][g[k]]);
    }
  }
  j=(1<<r)-1;
  for(i=0;i<r;i++)dp[j][0]=MIN(dp[j][i],dp[j][0]);
  printf("%d\n",dp[j][0]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&n,&m,&r);
   ^
./Main.c:6:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<r;i++)scanf("%d",&g[i]);
                   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&i,&j,&k);
     ^