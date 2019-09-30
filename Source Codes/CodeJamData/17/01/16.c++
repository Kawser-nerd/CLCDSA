#include <cassert>
#include <cstdio>
#include <cstring>

const int maxn = 1010;

int main () {
  int tn;
  assert (scanf ("%d", &tn) == 1);
  for (int tt = 1; tt <= tn; tt++) {
    char s[maxn + 10];
    int k;
    assert (scanf ("%s%d", s, &k) == 2);
    int n = strlen (s);
    for (int i = 0; i < n; i++)
      s[i] = (s[i] == '+');
    int ans = 0;
    for (int i = 0; i + k <= n; i++) {
      if (s[i])
        continue;
      ans++;
      for (int j = 0; j < k; j++)
        s[i + j] ^= 1;
    }
    bool ok = true;
    for (int i = 0; i < n; i++)
      ok = ok && s[i];
    if (ok)
      printf ("Case #%d: %d\n", tt, ans);
    else
      printf ("Case #%d: IMPOSSIBLE\n", tt);
  }
  return 0;
}

