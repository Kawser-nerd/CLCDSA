#include <cstdio>
#include <cstdlib>

int main() {
  int N;
  scanf("%d", &N);

  int x = 0;
  int y = 0;
  int t = 0;
  for (int i = 0; i < N; ++i) {
    int ti, xi, yi;
    scanf("%d %d %d", &ti, &xi, &yi);
    int dx = abs(x-xi);
    int dy = abs(y-yi);
    int dt = abs(t-ti);
    if (dx+dy > dt) return puts("No"), 0;
    if ((dx+dy) % 2 != dt % 2) return puts("No"), 0;
    x = xi;
    y = yi;
    t = ti;
  }
  puts("Yes");
}