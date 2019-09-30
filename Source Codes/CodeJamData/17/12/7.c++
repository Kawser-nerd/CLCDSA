#include <cassert>
#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

int main () {
  int tn;
  assert (scanf ("%d", &tn) == 1);
  for (int tt = 1; tt <= tn; tt++) {
    int n, p;
    assert (scanf ("%d%d", &n, &p) == 2);
    int a[n], b[n][p], pos[n];
    for (int i = 0; i < n; i++)
      assert (scanf ("%d", &a[i]) == 1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < p; j++)
        assert (scanf ("%d", &b[i][j]) == 1);
      sort (b[i], b[i] + p);
    }
    memset (pos, 0, sizeof (pos[0]) * n);
    int ans = 0, rt = 0;
    while (true) {
      bool finish = false;
      for (int i = 0; i < n; i++) {
        while (pos[i] < p && b[i][pos[i]] * 10 < 9 * a[i] * rt)
          pos[i]++;
        if (pos[i] == p)
          finish = true;
      }
      if (finish)
        break;
      bool ok = true;
      for (int i = 0; i < n; i++) {
        if (b[i][pos[i]] * 10 <= 11 * a[i] * rt)
          continue;
        ok = false;
        break;
      }
      if (!ok) {
        rt++;
        continue;
      }
      ans++;
      for (int i = 0; i < n; i++)
        pos[i]++;
    }
    printf ("Case #%d: %d\n", tt, ans);
  }
  return 0;
}

