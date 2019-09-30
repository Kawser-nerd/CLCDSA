#include<stdio.h>
int main(void){
  int A,B;
  scanf("%d %d",&A,&B);
  if(A>8 || B>8){
    printf(":(\n");
  }else{
    printf("Yay!\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&A,&B);
   ^