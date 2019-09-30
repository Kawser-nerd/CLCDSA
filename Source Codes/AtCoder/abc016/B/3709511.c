#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main(void) {
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  if(a+b==c && a-b==c) puts("?");
  else if(a+b==c) puts("+");
  else if(a-b==c) puts("-");
  else puts("!");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&c);
   ^