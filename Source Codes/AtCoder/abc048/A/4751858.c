#include <stdio.h>
int main()
{
  char a[101], s[101], b[101];
  scanf("%s %s %s", a,s,b);
  char out[4];
  snprintf(out,4,"%c%c%c", a[0],s[0],b[0]);
  printf("%s",out);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %s %s", a,s,b);
   ^