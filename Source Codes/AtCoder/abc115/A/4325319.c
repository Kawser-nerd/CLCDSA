#include <stdio.h>

int main(void)
{
  int d;
  scanf("%d", &d);

  switch (d) {
  case 25 : puts("Christmas");  break;
  case 24 : puts("Christmas Eve");  break;
  case 23 : puts("Christmas Eve Eve");  break;
  case 22 : puts("Christmas Eve Eve Eve");  break;
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &d);
   ^