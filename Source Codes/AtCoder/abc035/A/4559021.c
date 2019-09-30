#include<stdio.h>
int main(void){
  int w,h;
  scanf("%d %d",&w,&h);
  if(w*3==h*4){
    printf("4:3\n");
  }else{
    printf("16:9\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&w,&h);
   ^