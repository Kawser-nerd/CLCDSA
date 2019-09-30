#include <stdio.h>
#include <math.h>
int main(void){
  int n,dp[100001],a[100001];
  scanf("%d",&n);
  int i;
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  dp[0]=0;dp[1]=abs(a[1]-a[0]);
  for(i=2;i<n;i++){
    dp[i]=fmin(dp[i-1]+abs(a[i-1]-a[i]),dp[i-2]+abs(a[i-2]-a[i]));
  }
  printf("%d",dp[n-1]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:17: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
   dp[0]=0;dp[1]=abs(a[1]-a[0]);
                 ^
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^