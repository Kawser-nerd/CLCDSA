#include<stdio.h>

int main()
{
int a,b;
 scanf("%d%d",&a,&b);
  printf("%d",b%a?b-a:a+b);} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&a,&b);
  ^