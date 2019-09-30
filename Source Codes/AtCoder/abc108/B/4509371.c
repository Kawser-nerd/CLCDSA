#include <stdio.h>

int main(void) {
  int x[4], y[4];
  scanf("%d %d %d %d", &x[0], &y[0], &x[1], &y[1]);
  int dx, dy, i;
  // 90??????? (dx, dy)?????90?????[[0,-1],[1,0]]???????????
  for(i = 2; i < 4; ++i) {
    dx = x[i-1] - x[i-2]; dy = y[i-1] - y[i-2];
	x[i] = x[i-1] - dy;
    y[i] = y[i-1] + dx;
  }
  printf("%d %d %d %d\n", x[2], y[2], x[3], y[3]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d", &x[0], &y[0], &x[1], &y[1]);
   ^