#include <stdio.h>
int main(void){
int A,B,c;
  scanf("%d %d",&A,&B);
  c=A+B;
  if(A+B>=24){c=A+B-24;}
  printf("%d",c);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&A,&B);
   ^