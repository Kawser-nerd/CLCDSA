#include <stdio.h>

int main(void) 
{
  int n, ans = 0, c, cnt, x;
  scanf("%d", &n);
  for(c = 1; c <= n; c += 2) {
    cnt = 0;
    for(x = 1; x <= c; ++x) {
      if(c % x == 0) { ++cnt; }
    }
    if( cnt == 8) { ++ans; }
  }
  printf("%d\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^