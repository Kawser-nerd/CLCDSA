#include <stdio.h>

int main(void)
{
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);

  int ans;
  if (c <= a + b + 1)
    ans = b + c;
  else
    ans = b + a + b + 1;

  printf("%d\n", ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &a, &b, &c);
   ^