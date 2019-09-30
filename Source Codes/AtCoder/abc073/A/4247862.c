#include <stdio.h>

int main()
{
  char n[3];
  scanf("%s",n);
  if(n[0]=='9' || n[1]=='9') puts("Yes");
  else puts("No");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",n);
   ^