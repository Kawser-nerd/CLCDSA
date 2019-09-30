#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main(void){
  int x1,x2,x3,x4,y1,y2,y3,y4;
  scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
  int x=x2-x1,y=y2-y1;
  x3=x2-y,y3=y2+x,x4=x1-y,y4=y1+x;
  printf("%d %d %d %d\n",x3,y3,x4,y4);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
   ^