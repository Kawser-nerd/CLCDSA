#include<stdio.h>
int main(void){

  int a;
  scanf("%d",&a);

  if (a % 2 == 0){
    printf("Blue\n");
  }else{
    printf("Red\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^