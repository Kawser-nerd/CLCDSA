#include <stdio.h>

int
main(int atgc, char *argv[])
{
  int c, a, b;
  scanf("%d%d%d", &c, &a, &b);
  printf("%d", c * a / 2);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &c, &a, &b);
   ^