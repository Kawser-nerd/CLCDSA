#include <bits/stdc++.h>

using namespace std;

const int N = 777;

int r[N], q[N][N], ptr[N];

int main() {
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int n, p;
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; i++) {
      scanf("%d", r + i);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < p; j++) {
        scanf("%d", q[i] + j);
      }
      sort(q[i], q[i] + p);
      ptr[i] = 0;
    }
    int ans = 0;
    while (true) {
      bool ok = true;
      int min_x = -1, max_x = (int) 1e9;
      int move_id = -1;
      for (int i = 0; i < n; i++) {
//        0.9 * r[i] * x <= q[i][ptr[i]] <= 1.1 * r[i] * x
        if (ptr[i] == p) {
          ok = false;
          break;
        }
        int lx = (q[i][ptr[i]] * 10 - 1) / (11 * r[i]) + 1;
        int rx = q[i][ptr[i]] * 10 / (9 * r[i]);
        if (rx < max_x) {
          move_id = i;
        }
        min_x = max(min_x, lx);
        max_x = min(max_x, rx);
      }
      if (!ok) {
        break;
      }
      if (min_x <= max_x) {
        ans++;
        for (int i = 0; i < n; i++) {
          ptr[i]++;
        }
        continue;
      }
      ptr[move_id]++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
