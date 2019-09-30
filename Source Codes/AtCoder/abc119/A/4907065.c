#include<stdio.h>

int main()
{
int a,b,c;
scanf("%d/%d/%d",&a,&b,&c);
if(b<=4)printf("Heisei");
  else printf("TBD");
} ./Main.c: In function ‘main’:
./Main.c:6:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d/%d/%d",&a,&b,&c);
 ^