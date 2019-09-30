#include <stdio.h>
#include <stdlib.h>
int comp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
int main() {
  int n,a[300000],i;
  long long x=0;
  scanf("%d",&n);
  for (i=0;i<3*n;i++) {
    scanf("%d",&a[i]);
  }
  qsort(a, 3*n, sizeof(int), comp);
  for (i=n;i<3*n;i+=2) {
    x+=a[i];
  }
  printf("%lld\n",x);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^