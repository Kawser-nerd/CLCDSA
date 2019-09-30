#include<stdio.h>

int main(void)
{
  int a;
  int b;
  int c;
  scanf("%d %d",&a,&b);
  c=a;
  a=b;
  b=c;
  printf("%d %d\n",a,b);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^