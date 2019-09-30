#include <stdio.h>
#include <stdlib.h>
int main() {
  int n,i,a[100001],diff[100000],x[2];
  long long sum=0;
  a[0]=0;
  scanf("%d",&n);
  for (i = 1;i <= n;i++) {
    scanf("%d",&a[i]);
    x[0]=abs(a[i]-a[i-1]);
    sum+=x[0];
    if (i!=1) {
      diff[i-2]=abs(a[i]-a[i-2])-x[0]-x[1];
    }
    x[1]=x[0];
  }
  sum+=abs(a[n]);
  diff[n-1]=abs(a[n-1])-x[1]-abs(a[n]);
  for (i = 0; i < n; i++) {
    printf("%lld\n",sum+diff[i]);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^