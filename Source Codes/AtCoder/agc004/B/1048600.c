#include <stdio.h>

#define MIN(x,y) ((x)<(y)?(x):(y))

typedef long long int ll;

int a[2000];

int dp[2000][2000];
ll dp2[2000];

int main(){
  int n, x, i, j;
  scanf("%d%d", &n, &x);
  for(i=0;i<n;i++){
    scanf("%d", a+i);
    dp2[0] += dp[i][0] = a[i];
  }

  for(j=1;j<n;j++){
    dp2[j] = (ll) j*x;
    for(i=0;i<n;i++){
      dp2[j] += dp[i][j] = MIN(dp[i][j-1], a[(i+n-j)%n]);
    }
    dp2[j] = MIN(dp2[j-1], dp2[j]);
  }

  printf("%lld\n", dp2[n-1]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &n, &x);
   ^
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", a+i);
     ^