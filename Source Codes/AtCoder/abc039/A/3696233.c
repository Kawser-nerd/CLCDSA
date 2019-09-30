#include<stdio.h>

int main(void){
int a,b,c;
scanf("%d",&a);
scanf("%d",&b);
scanf("%d",&c);
printf("%d",2*a*b+2*b*c+2*a*c);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&a);
 ^
./Main.c:6:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&b);
 ^
./Main.c:7:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&c);
 ^