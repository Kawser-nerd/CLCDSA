#include <stdio.h>
#include <stdlib.h>

#define SQ(X) ((X) * (X))

static int x1;
static int y1;
static int r;
static int x2;
static int x3;
static int y2;
static int y3;

int main(int argc, char *argv[]) {
  scanf("%d%d%d%d%d%d%d", &x1, &y1, &r, &x2, &y2, &x3, &y3);
  
  if ((x2 <= x1 - r && x1 + r <= x3) && (y2 <= y1 - r && y1 + r <= y3)) {
    puts("NO");
  } else {
    puts("YES");
  }

  if ((SQ(x2 - x1) + SQ(y2 - y1) <= SQ(r)) && (SQ(x3 - x1) + SQ(y3 - y1) <= SQ(r))
      && (SQ(x2 - x1) + SQ(y3 - y1) <= SQ(r)) && (SQ(x3 - x1) + SQ(y2 - y1) <= SQ(r))) {
    puts("NO");
  } else {
    puts("YES");
  }

  return (EXIT_SUCCESS);
} ./Main.c: In function ‘main’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d%d%d%d", &x1, &y1, &r, &x2, &y2, &x3, &y3);
   ^