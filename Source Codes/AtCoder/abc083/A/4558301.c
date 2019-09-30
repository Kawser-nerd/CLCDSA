#include<stdio.h>
int main(void){
  int a,b,c,d,left,right;
  scanf("%d %d %d %d",&a,&b,&c,&d);
  left=a+b;
  right=c+d;
  if(left>right){
    printf("Left\n");
  }else if(left==right){
    printf("Balanced\n");
  }else{
    printf("Right\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d",&a,&b,&c,&d);
   ^