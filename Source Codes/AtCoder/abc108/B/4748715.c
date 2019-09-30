#include <stdio.h>

int main() {
  int x1,x2,y1,y2;
  scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
  int dif_1,dif_2;
  dif_1 = x2 - x1;
  int y3 = y2 + dif_1;
  dif_2 = y2 - y1;
  int x3 = x2 - dif_2;
  int x4,y4;
  x4 = x3 - dif_1;
  y4 = y3 - dif_2;
  printf("%d %d %d %d\n",x3,y3,x4,y4);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
   ^