#include<stdio.h>

int main(void)
{
  int h1,h2,s;
  
  scanf("%d%d",&h1,&h2);
  s=h1-h2;
  printf("%d\n",s);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&h1,&h2);
   ^