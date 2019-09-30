#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b){
  return *(int *)b - *(int *)a;
}
int main(int argc, char const *argv[]) {
  int n,k;
  scanf("%d%d", &n, &k);
  int l[n];
  int i;
  for (i = 0;i < n;i++) {
    scanf("%d", &l[i]);
  }
  qsort(l, n, sizeof(int), compare);
  int ans = 0;
  for(i=0;i<k;i++){
    ans += l[i];
  }
  printf("%d\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &n, &k);
   ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &l[i]);
     ^