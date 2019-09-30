#include <stdio.h>

int main()
{
  int a, b, x;
  scanf("%d%d%d", &a, &b, &x);
  if (a + b < x || a > x)
    puts("NO");
  else
    puts("YES");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &a, &b, &x);
   ^