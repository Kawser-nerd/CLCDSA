#include <bits/stdc++.h>

using namespace std;

const int N = 2345678;

int balance[N], s[N], m[N], from[N], to[N];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int n, d;
    scanf("%d %d", &n, &d);
    int As, Cs, Rs;
    int Am, Cm, Rm;
    scanf("%d %d %d %d", s + 0, &As, &Cs, &Rs);
    scanf("%d %d %d %d", m + 0, &Am, &Cm, &Rm);
    for (int i = 1; i < n; i++) {
      s[i] = ((long long)s[i - 1] * As + Cs) % Rs;
      m[i] = ((long long)m[i - 1] * Am + Cm) % Rm;
    }
    for (int i = 1; i < n; i++) {
      m[i] %= i;
    }
    from[0] = s[0];
    to[0] = s[0];
    for (int i = 1; i < n; i++) {
      from[i] = min(s[i], from[m[i]]);
      to[i] = max(s[i], to[m[i]]);
    }
    for (int i = 0; i < Rs; i++) {
      balance[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      if (to[i] - from[i] <= d) {
        balance[max(0, to[i] - d)]++;
        balance[from[i] + 1]--;
      }
    }
    int ans = 0;
    int cur = 0;
    for (int i = 0; i < Rs; i++) {
      cur += balance[i];
      ans = max(ans, cur);
    }
    printf("%d\n", ans);
  }
  return 0;
}
