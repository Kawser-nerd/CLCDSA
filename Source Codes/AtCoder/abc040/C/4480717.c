#include <stdio.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) ((a)>(0)?(a):-(a))
int main(){
  int n;
  scanf("%d",&n);
  int a[n],dp[n+1],j,k,i;
  for(i=0;i<n;i++)scanf("%d",&a[i]);
  dp[0]=0;
  dp[1]=abs(a[0]-a[1]);
  for(i=1;i<n;i++){
    j=dp[i]+abs(a[i]-a[i+1]);
    k=dp[i-1]+abs(a[i-1]-a[i+1]);
    dp[i+1]=min(j,k);
  }
    printf("%d",dp[n-1]);
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:8:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%d",&a[i]);
                   ^