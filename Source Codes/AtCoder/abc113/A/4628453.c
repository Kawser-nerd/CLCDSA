#include<stdio.h>
int main(void){
  int X,Y;
  scanf("%d %d",&X,&Y);
  printf("%d\n",X+Y/2);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&X,&Y);
   ^