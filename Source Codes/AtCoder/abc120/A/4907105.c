#include<stdio.h>

int main()
{
int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  printf("%d",b/a<=c?b/a:c);
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&c);
   ^