#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);

  if (abs(a - c) <= d || (abs(a - b) <= d && abs(c - b) <= d))
    puts("Yes");
  else
    puts("No");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d", &a, &b, &c, &d);
   ^