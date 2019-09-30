#include <stdio.h>

int main()
{
  long int a,b,c,d;
  
  scanf("%ld %ld %ld %ld", &a,&b,&c,&d);
  printf("%ld", (a*b>c*d) ? a*b : c*d);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld %ld %ld", &a,&b,&c,&d);
   ^