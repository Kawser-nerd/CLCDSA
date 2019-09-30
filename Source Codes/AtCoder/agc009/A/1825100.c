#include <stdio.h>
int main() {
  int n,i,a[100000],b[100000];
  long long c=0;
  scanf("%d",&n);
  for (i=0;i<n;i++) {
    scanf("%d %d",&a[i],&b[i]);
  }
  while (n--) {
    c+=(b[n]-(a[n]+c)%b[n])%b[n];
  }
  printf("%lld\n",c);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a[i],&b[i]);
     ^