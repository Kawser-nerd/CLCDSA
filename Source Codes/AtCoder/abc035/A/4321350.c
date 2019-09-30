#include<stdio.h>

int main(void){
  int w,h;
  scanf("%d%d",&w,&h);
  if((w%16==0) && (h%9==0)) printf("16:9\n");
  else printf("4:3\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&w,&h);
   ^