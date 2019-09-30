#include <stdio.h>
#include <math.h>
int main(void){
  int x,y,z,sum;
  scanf("%d%d%d",&x,&y,&z);
  x-=z;
  int count=x/(y+z);
  printf("%d",count);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&x,&y,&z);
   ^