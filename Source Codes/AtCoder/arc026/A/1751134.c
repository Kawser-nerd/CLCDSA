#include<stdio.h>
int main(void)
{
int i,n,b,c,a;


scanf("%d",&a);
scanf("%d",&b);
scanf("%d",&c);

if(a<=5){
printf("%d\n",a*c);}
else if(a>5){
printf("%d\n",c*5+((a-5)*b));}



return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&a);
 ^
./Main.c:8:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&b);
 ^
./Main.c:9:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&c);
 ^