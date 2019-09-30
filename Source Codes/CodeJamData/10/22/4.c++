#include <cassert>
#include <cstdio>

int main() {
  int tn;
  assert(scanf("%d", &tn) == 1);
  for (int tt = 1; tt <= tn; tt++) {
    int n, k, b, t;
    assert(scanf("%d%d%d%d", &n, &k, &b, &t) == 4);
    int x[n], v[n], p[n];
    for (int i = 0; i < n; i++)
      assert(scanf("%d", &x[i]) == 1), p[i] = i;
    for (int i = 0; i < n; i++)
      assert(scanf("%d", &v[i]) == 1);
    int bad = 0, res = 0, ans = 0;
    for (int i = n - 1; i >= 0 && res < k; i--)
      if ((b - x[i]) <= t * v[i])
        ans += bad, res++;
      else
        bad++;
    if (res == k)
      printf("Case #%d: %d\n", tt, ans);
    else
      printf("Case #%d: IMPOSSIBLE\n", tt);
  }
  return 0;
}

