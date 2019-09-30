#include<stdio.h>

int main(void)
{
  int x;
  scanf("%d",&x);
  printf("%d\n",x-1);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&x);
   ^