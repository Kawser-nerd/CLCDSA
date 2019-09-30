#include <cassert>
#include <cstdio>

int main () {
  int tn, n;
  assert (scanf ("%d", &tn) == 1);
  // for (int n = 1; n <= 1000000; n++) {
  for (int tt = 1; tt <= tn; tt++) {
    assert (scanf ("%d", &n) == 1);
    if (n == 0) {
      printf ("Case #%d: INSOMNIA\n", tt);
      continue;
    }
    int ans = 0;
    bool ok[10], ok_all = false;
    for (int i = 0; i < 10; i++)
      ok[i] = false;
    for (long long x = n; !ok_all; x += n) {
      ans++;
      for (long long y = x; y > 0; y /= 10)
        ok[y % 10] = true;
      ok_all = true;
      for (int i = 0; i < 10; i++)
        if (!ok[i])
          ok_all = false;
    }
    printf ("Case #%d: %lld\n", tt, (long long)ans * n);
  }
  return 0;
}
