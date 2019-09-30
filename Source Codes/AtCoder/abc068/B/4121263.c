#include <stdio.h>

int main()
{
  int n;
  int ans = 1;
  scanf("%d", &n);

  while (ans * 2 <= n) {
    ans = ans * 2;
  }

  printf("%d", ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^