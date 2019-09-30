#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int comp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
int main() {
  int n,a[100000],i;
  double x,y[2];
  scanf("%d",&n);
  for (i=0;i<n;i++) {
    scanf("%d",&a[i]);
  }
  qsort(a, n, sizeof(int), comp);
  x=(double)a[n-1]/2;
  y[1]=a[n-1];
  for (i=0;i<n;i++) {
    y[0]=fabs(a[i]-x);
    if (y[0]>y[1]) {
      printf("%d %d\n",a[n-1],a[i-1]);
      return 0;
    }
    y[1]=y[0];
  }
  printf("%d %d\n",a[n-1],a[0]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^