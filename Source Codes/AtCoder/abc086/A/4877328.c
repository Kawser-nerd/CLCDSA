#include<stdio.h>

int main(void){
  int a;
  int b;

  scanf("%d",&a);
  scanf("%d",&b);


  int seki;
  seki = a * b;
  int hantei;
  hantei = seki % 2;

  if(hantei == 1){

    printf("Odd");

  }else{

    printf("Even");

  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&b);
   ^