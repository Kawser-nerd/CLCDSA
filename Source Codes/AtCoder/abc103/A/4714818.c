#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
  int p = *(int*)a, q = *(int*)b;
  if( p > q ) { return 1; }
  else if( p == q ) { return 0; }
  else { return -1; }
}

int main(void)
{
  int a[3], i, ans = 0;
  for(i = 0; i < 3; ++i) { scanf("%d", &a[i]); }
  qsort(a, 3, sizeof(int), cmp);
  for(i = 1; i < 3; ++i) { ans += a[i] - a[i-1]; }
  printf("%d\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i = 0; i < 3; ++i) { scanf("%d", &a[i]); }
                            ^