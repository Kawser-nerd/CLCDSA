#include<stdio.h>

int main(void)
{
  char n;
  scanf("%c",&n);
  printf("%d\n",n-'A'+1);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c",&n);
   ^