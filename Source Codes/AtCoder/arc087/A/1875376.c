#include <stdio.h>
#include <stdlib.h>
int comp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
int main() {
  int n,a[100000],i,d=1,ans=0;
  scanf("%d",&n);
  for (i=0;i<n;i++) {
    scanf("%d",&a[i]);
  }
  qsort(a, n, sizeof(int), comp);
  for (i=0;i<n;i++) {
    while (a[i]==a[i+1]) {
      d++;
      i++;
    }
    if (d<a[i]) {
      ans+=d;
    } else {
      ans+=d-a[i];
    }
    d=1;
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^