#include <cstdio>
#include <algorithm>

int main() {
  int x1, y1, x2, y2;
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

  int dx = x2-x1;
  int dy = y2-y1;
  y2 += dx;
  x2 -= dy;
  printf("%d %d ", x2, y2);

  x2 -= dx;
  y2 -= dy;
  printf("%d %d\n", x2, y2);
}