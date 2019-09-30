#include <stdio.h>
#define MAXN 100
int f[MAXN][MAXN];
int c[MAXN][MAXN];
int g[MAXN][MAXN];
double best[MAXN][MAXN];

#define INF 1000000000
#define EPS 1e-10

double count (int h, double t, int f1, int c1, int f2, int c2) {
  double cl = (t < 0) ? h : h - 10 * t;
  if (c2 < f2 + 50 || c2 < f1 + 50) {
    return INF;
  }
  if (c1 < f2 + 50) {
    return INF;
  }
  if (cl + 50 > c2) {
    t = (h + 50 - c2) * 0.1;
  }
  cl = (t < 0) ? h : h - 10 * t;
  if (cl - 20 + EPS > f1) {
    return t + 1;
  } else {
    return t + 10;
  }
}

int main () {
  int __;
  scanf ("%d", &__);
  int _;
  for (_ = 0; _ < __; _ ++) {
    printf ("Case #%d:", _ + 1);
    int n, m, h;
    scanf ("%d%d%d", &h, &n, &m);
    int i, j;
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++) {
        scanf ("%d", &c[i][j]);
      }
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++) {
        scanf ("%d", &f[i][j]);
      }
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++) {
        best[i][j] = INF;
        g[i][j] = 0;
      }
    best[0][0] = -INF;

    while (1) {
      int bb = INF;
      int x = -1;
      int y = -1;
      for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) 
          if (!g[i][j] && bb > best[i][j]) {
            bb = best[i][j];
            x = i;
            y = j;
          }
      if (x == -1) {
        break;
      }
      if (x == n - 1 && y == m - 1) {
        break;
      }
      g[x][y] = 1;
      double t = best[x][y];
      if (x != 0) {
        double tt = count (h, t, f[x][y], c[x][y], f[x - 1][y], c[x - 1][y]);
        if (tt < best[x - 1][y]) {
          best[x - 1][y] = tt;
        }
      }
      if (x != n - 1) {
        double tt = count (h, t, f[x][y], c[x][y], f[x + 1][y], c[x + 1][y]);
        if (tt < best[x + 1][y]) {
          best[x + 1][y] = tt;
        }
      }
      if (y != 0) {
        double tt = count (h, t, f[x][y], c[x][y], f[x][y - 1], c[x][y - 1]);
        if (tt < best[x][y - 1]) {
          best[x][y - 1] = tt;
        }
      }
      if (y != m - 1) {
        double tt = count (h, t, f[x][y], c[x][y], f[x][y + 1], c[x][y + 1]);
        if (tt < best[x][y + 1]) {
          best[x][y + 1] = tt;
        }
      }      
    }
    double tt = best[n - 1][m - 1];
    if (tt < 0) {
      tt = 0;
    }
    printf (" %lf\n", tt);
  }
  return 0;
}
