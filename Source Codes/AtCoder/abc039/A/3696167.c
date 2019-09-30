#include<stdio.h>
int main(void){
  int A,B,C,D,E,F;
scanf("%d",&A);
scanf("%d",&B);
scanf("%d",&C);
D=A*B;
  E=B*C;
  F=A*C;
printf("%d",(D+E+F)*2);

return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&A);
 ^
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&B);
 ^
./Main.c:6:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&C);
 ^