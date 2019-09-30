#include <cassert>
#include <cstdio>

int main () {
  int tn;
  assert (scanf ("%d", &tn) == 1);
  for (int tt = 1; tt <= tn; tt++) {
    int k, c, s;
    assert (scanf ("%d%d%d", &k, &c, &s) == 3);
    if (k > c * s) {
      printf ("Case #%d: IMPOSSIBLE\n", tt);
      continue;
    }
    long long ans[s];
    int ansk = 0;
    for (int t = 0; t < k; ) {
      long long x = 0;
      for (int i = 0; i < c; i++, t++) {
        x = x * k;
        if (t < k)
          x += t;
      }
      ans[ansk++] = x;
    }
    printf ("Case #%d:", tt);
    for (int i = 0; i < ansk; i++)
      printf (" %lld", ans[i] + 1);
    puts ("");
  }
  return 0;
}

