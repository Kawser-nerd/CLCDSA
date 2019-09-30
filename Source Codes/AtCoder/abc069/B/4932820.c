#include <stdio.h>
#include <math.h>
#include <string.h>
int main(void)
{
 char s[256];
 char first, last;
 int n;
 scanf("%s", s);
 n = strlen(s) - 2;
 first = s[0];
 last = s[n+1];
 printf("%c%d%c", first, n, last);
 return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^