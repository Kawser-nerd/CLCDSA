#include <stdio.h>

int main(void)
{
  int h, w;
  scanf("%d %d", &h, &w);

  printf("%d\n", 2 * w * h - h - w);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &h, &w);
   ^