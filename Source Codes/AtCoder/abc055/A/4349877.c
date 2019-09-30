#include<stdio.h>

int main(void){
  int n,x,y;
  scanf("%d",&n);
  x=n*800;
  y=n/15*200;
  printf("%d\n",x-y);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^