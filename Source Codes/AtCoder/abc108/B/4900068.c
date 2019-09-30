#include <stdio.h>

int
main(int argc, char *argv[])
{
  int x[4], y[4];
  scanf("%d%d%d%d",&x[0], &y[0], &x[1], &y[1]);
  
  x[2] = x[1] + y[0] - y[1];
  y[2] = -x[0] + x[1] + y[1];
  x[3] = x[0] + y[0] - y[1];
  y[3] = x[1] - x[0] + y[0];
  
  printf("%d %d %d %d", x[2], y[2], x[3], y[3]);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&x[0], &y[0], &x[1], &y[1]);
   ^