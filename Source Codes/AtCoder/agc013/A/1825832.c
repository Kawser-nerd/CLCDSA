#include <stdio.h>
#include <stdlib.h>
int main() {
  int n,a[100000],i,d=0,x=1;
  scanf("%d",&n);
  for (i=0;i<n;i++) {
    scanf("%d",&a[i]);
  }
  for (i=1;i<n;i++) {
    if (d==0&&a[i]-a[i-1]!=0) {
      d=(a[i]-a[i-1])/(abs(a[i]-a[i-1]));
    }
    if (d*(a[i]-a[i-1])<0) {
      x++;
      d=0;
    }
  }
  printf("%d\n",x);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^