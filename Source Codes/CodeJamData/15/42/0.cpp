#include <bits/stdc++.h>

using namespace std;

const int N = 12345;

double r[N], c[N], a[N];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int n;
    double v, x;
    scanf("%d %lf %lf", &n, &v, &x);
    for (int i = 0; i < n; i++) {
      scanf("%lf %lf", r + i, c + i);
      c[i] -= x;
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (c[i] > c[j]) {
          swap(r[i], r[j]);
          swap(c[i], c[j]);
        }
      }
    }
    double low = 0, high = 1e20;
    for (int it = 0; it < 500; it++) {
      double mid = 0.5 * (low + high);
      for (int i = 0; i < n; i++) {
        a[i] = r[i] * mid;
      }
      double have = 0.0;
      int p = -1, q = n;
      for (int i = 0; i < n; i++) {
        if (c[i] < 0) {
          p++;
        }
        if (c[i] > 0) {
          q--;
        }
        if (c[i] == 0) {
          have += a[i];
          a[i] = 0.0;
        }
      }
      while (p >= 0 && q < n) {
        double z = min(a[q] / (-c[p]), a[p] / c[q]);
        have += z * (-c[p]) + z * c[q];
        a[q] -= z * (-c[p]);
        a[p] -= z * c[q];
        if (a[p] < 1e-9) p--;
        if (a[q] < 1e-9) q++;
      }
      if (have >= v) {
        high = mid;
      } else {
        low = mid;
      }
    }
    if (low > 1e19) {
      puts("IMPOSSIBLE");
    } else {
      printf("%.9f\n", 0.5 * (low + high));
    }
  }
  return 0;
}
