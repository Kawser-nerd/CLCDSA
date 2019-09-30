#include<stdio.h>
 
int main(void)
{
  int i,N,x=0,y=0;
  scanf("%d",&N);
  for(i=1;i<=N;i++){
    x+=800;
    if((i%15)==0){
      y+=200;
    }
  }
  printf("%d",x-y);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^