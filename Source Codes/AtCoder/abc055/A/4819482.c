#include<stdio.h>
int main(void){
  int N;
  scanf("%d",&N);
  int x=N*800;
  int y=(N/15)*200;
  printf("%d\n",x-y);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^