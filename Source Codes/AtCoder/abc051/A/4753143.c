#include <stdio.h>

int main()
{
  char s[20], *tp;
  scanf("%s", s);
  s[5] = ' ';
  s[13] = ' ';
  printf("%s", s);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^