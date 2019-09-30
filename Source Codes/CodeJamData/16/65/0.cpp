#include <bits/stdc++.h>

using namespace std;

const double inf = 1e9;

const int NX = 100;
const int NY = 4000;
const int MAGIC = 200;

const double ys = -20.0;
const double yf = 20.0;
const double xs = -10.0;
const double xf = 10.0;

double step_x, step_y;
int n;
double c[42];

inline double calc(int xxa, int yya, int xxb, int yyb) {
  double xa = xs + xxa * step_x;
  double ya = ys + yya * step_y;
  double xb = xs + xxb * step_x;
  double yb = ys + yyb * step_y;
  double d = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
  double dose = 0;
  for (int i = 0; i < n; i++) {
    double dist = xa * xa + (ya - c[i]) * (ya - c[i]);
    if (dist < 1e-7) {
      return inf;
    }
    dose += 1.0 / dist;
  }
  for (int i = 0; i < n; i++) {
    double dist = xb * xb + (yb - c[i]) * (yb - c[i]);
    if (dist < 1e-7) {
      return inf;
    }
    dose += 1.0 / dist;
  }
  dose *= 0.5;
  dose += 1.0;
  return dose * d;
}

double f[NY + 10], nf[NY + 10];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  step_x = (xf - xs) / NX;
  step_y = (yf - ys) / NY;
  cerr << "step_x = " << step_x << ", step_y = " << step_y << endl;
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    double A, B;
    cin >> n >> A >> B;
    for (int i = 0; i < n; i++) {
      cin >> c[i];
    }
    for (int j = 0; j <= NY; j++) {
      f[j] = inf;
    }
    int start_y = (int) ((A - ys) / step_y + 0.5);
    f[start_y] = 0.0;
    for (int i = 1; i <= NX; i++) {
      for (int j = 0; j <= NY; j++) {
        nf[j] = inf;
        int lk = max(0, j - MAGIC);
        int rk = min(NY, j + MAGIC);
        for (int k = lk; k <= rk; k++) {
          double ft = f[k] + calc(i - 1, j, i, k);
          nf[j] = min(nf[j], ft);
        }
      }
      for (int j = 0; j <= NY; j++) {
        f[j] = nf[j];
      }
    }
    int finish_y = (int) ((B - ys) / step_y + 0.5);
    printf("%.17f\n", f[finish_y]);
    fflush(stdout);
    fprintf(stderr, "test case %d solved\n", qq);
    fflush(stderr);
  }
  return 0;
}
