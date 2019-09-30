#include<stdio.h>

int main(){
  int i,n,a,x[50],j;
  long long int dp[51][5001]={};
  scanf("%d %d",&n,&a);
  for(i=0;i<n;i++){
    scanf("%d",&x[i]);
    x[i]-=a;
  }
  dp[0][n*50]=1;
  for(i=0;i<n;i++){
    for(j=0;j<=2*n*50;j++){
      if((j-x[i])<=n*100&&(j-x[i])>=0)
        dp[i+1][j]=dp[i][j]+dp[i][j-x[i]];
      else
        dp[i+1][j]=dp[i][j];
    }
  }
  printf("%ld\n",dp[n][50*n]-1);
} ./Main.c: In function ‘main’:
./Main.c:20:10: warning: format ‘%ld’ expects argument of type ‘long int’, but argument 2 has type ‘long long int’ [-Wformat=]
   printf("%ld\n",dp[n][50*n]-1);
          ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&a);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&x[i]);
     ^