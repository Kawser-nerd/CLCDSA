#include <stdio.h>
#include <math.h>

char result[BUFSIZ];

#define SQ(x) ((x) * (x))

double area(int ax, int ay, int bx, int by, int cx, int cy) {
  double a, b, c, s;
  a = sqrt(SQ(ax - bx) + SQ(ay - by));
  b = sqrt(SQ(cx - bx) + SQ(cy - by));
  c = sqrt(SQ(ax - cx) + SQ(ay - cy));
  s = (a + b + c) / 2;
  return sqrt(s * (s-a) * (s-b) * (s-c));
}

void run_case() {
  int n, m, a;
  int x1, y1, x2, y2;
  scanf("%d %d %d", &n, &m, &a);
  for (x1 = 0; x1 <= n; x1++) {
    for (y1 = 0; y1 <= m; y1++) {
      if (! x1 && !y1)
        break;
      for (x2 = 0; x2 <= n; x2++) {
        for (y2 = 0; y2 <= m; y2++) {
          if (!x2 && !y2)
            break;
          if (x1 == x2 && y1 == y2)
            break;
          if (fabs(area(0, 0, x1, y1, x2, y2) - (a/2.0)) < 1e-4) {
            sprintf(result, "0 0 %d %d %d %d", x1, y1, x2, y2);
            return;
          }
        }
      }
    }
  }
  sprintf(result, "IMPOSSIBLE");
}

int main() {
  int cases, i;

  scanf("%d", &cases);
  for (i = 1; i <= cases; i++) {
    run_case();
    printf("Case #%d: %s\n", i, result);
  }
  return 0;
}
