#include <bits/stdc++.h>

using namespace std;

double p[12345];
double f[444][444];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
      scanf("%lf", p + i);
    }
    sort(p, p + n);
    double ans = 0.0;
    for (int take = 0; take <= k; take++) {
      vector <double> q;
      for (int i = 0; i < take; i++) {
        q.push_back(p[i]);
      }
      for (int i = 0; i < k - take; i++) {
        q.push_back(p[n - 1 - i]);
      }
      for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= i; j++) {
          f[i][j] = 0.0;
        }
      }
      f[0][0] = 1.0;
      for (int i = 0; i < k; i++) {
        for (int j = 0; j <= i; j++) {
          f[i + 1][j] += f[i][j] * (1.0 - q[i]);
          f[i + 1][j + 1] += f[i][j] * q[i];
        }
      }
      ans = max(ans, f[k][k / 2]);
    }
    printf("%.17f\n", ans);
  }
  return 0;
}
