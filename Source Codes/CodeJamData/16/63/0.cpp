#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-9;

const int N = 333;

double from[N][N], to[N][N], d[N][N];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int n, _r;
    scanf("%d %d", &n, &_r);
    double r = 1e-6 * _r;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 && j == 0) {
          continue;
        }
        double real = atan2(j, i);
        d[i][j] = sqrt(i * i + j * j);
        double shift = asin(r / d[i][j]);
        from[i][j] = real - shift;
        to[i][j] = real + shift;
      }
    }
    double cur = 0.0;
    int ans = 0;
    while (true) {
      double best = 1e30, bd = 1e30;
      int bi = -1, bj = -1;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (to[i][j] < cur + eps) {
            continue;
          }
          double ff = max(from[i][j], cur);
          if (ff < best - eps || (fabs(ff - best) < eps && d[i][j] < bd)) {
            best = ff;
            bd = d[i][j];
            bi = i;
            bj = j;
          }
          break;
        }
      }
      if (bi == -1) {
        break;
      }
      ans++;
      cur = to[bi][bj];
    }
    printf("%d\n", ans);
    fprintf(stderr, "test case %d solved\n", qq);
    fflush(stderr);
  }
  return 0;
}
