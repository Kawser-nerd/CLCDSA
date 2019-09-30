#include<stdio.h>

int main(void)
{
  int a=0,b=0,c=0,d=0;

 scanf("%d",&a);
 scanf("%d",&b);
 scanf("%d",&c);
 
 d=b/a;

 if(c < d) d=c;

 printf("%d",d);

return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&a);
  ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&b);
  ^
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&c);
  ^