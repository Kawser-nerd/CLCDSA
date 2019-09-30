#include<stdio.h>

long long max(long long a,long long b){if(a>b){return a;}return b;}

int main(){
  long long i,j,x,y,n,t,h,dp[1024][1024]={0},r=0,k;
  scanf("%lld%lld%lld",&x,&y,&n);
  y+=x;
  for(i=0;i<1024;i++){
    for(j=0;j<1024;j++){dp[i][j]=-123456789012;}
  }
  dp[0][0]=0;
  for(i=0;i<n;i++){
    scanf("%lld%lld",&t,&h);
    for(j=i+1;j>0;j--){
      for(k=0;k<(666-t);k++){
        dp[j][k+t]=max(dp[j][k+t],dp[j-1][k]+h);
      }
    }
  }
  for(i=0;i<=x;i++){
    for(j=0;j<=y;j++){r=max(r,dp[i][j]);}
  }
  printf("%lld\n",r);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld",&x,&y,&n);
   ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&t,&h);
     ^