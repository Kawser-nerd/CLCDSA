#include <bits/stdc++.h>

using namespace std;

const int N = 77777;

double d[N];
int x[N], y[N], z[N], vx[N], vy[N], vz[N];
bool b[N];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int n, s;
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++) {
      scanf("%d %d %d %d %d %d", x + i, y + i, z + i, vx + i, vy + i, vz + i);
    }
    for (int i = 0; i < n; i++) {
      d[i] = 1e9;
      b[i] = true;
    }
    d[0] = 0;
    for (int it = 0; it < n; it++) {
      int best = -1;
      for (int i = 0; i < n; i++) {
        if (!b[i]) {
          continue;
        }
        if (best == -1 || d[i] < d[best]) {
          best = i;
        }
      }
      b[best] = false;
      for (int j = 0; j < n; j++) {
        double dist = sqrt((x[best] - x[j]) * (x[best] - x[j]) + (y[best] - y[j]) * (y[best] - y[j]) + (z[best] - z[j]) * (z[best] - z[j]));
        double dt = max(d[best], dist);
        d[j] = min(d[j], dt);
      }
    }
    printf("%.17f\n", d[1]);
  }
  return 0;
}
