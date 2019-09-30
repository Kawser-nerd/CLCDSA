#include <stdio.h>
#include <stdlib.h>
int comp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
int main() {
  int n,k,a[200000],b[200000]={0},i,ans,j;
  scanf("%d %d",&n,&k);
  for (i=0;i<n;i++) {
    scanf("%d",&a[i]);
  }
  for (i=0;i<n;i++) {
    b[a[i]-1]++;
  }
  qsort(b, n, sizeof(int), comp);
  for (i=0;i<n-k;i++) {
    ans+=b[i];
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&k);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^