#include <stdio.h>
#include <stdlib.h>
int comp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
int main() {
  int n,x[200000],y[200000],i;
  scanf("%d",&n);
  for (i = 0;i<n;i++) {
    scanf("%d",&x[i]);
    y[i]=x[i];
  }
  qsort(x, n, sizeof(int), comp);
  for (i = 0;i < n;i++) {
    if (y[i]<=x[n/2-1]) {
      printf("%d\n",x[n/2]);
    } else {
      printf("%d\n",x[n/2-1]);
    }
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&x[i]);
     ^