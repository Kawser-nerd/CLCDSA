#include <stdio.h>
#include <math.h>

int main()
{
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);

  printf("%d\n", (int)(fmin(a, b) + fmin(c, d)));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d", &a, &b, &c, &d);
   ^