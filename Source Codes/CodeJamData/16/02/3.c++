#include <cassert>
#include <cstdio>
#include <cstring>

int main () {
  int tn;
  assert (scanf ("%d ", &tn) == 1);
  for (int tt = 1; tt <= tn; tt++) {
    char s[110];
    assert (scanf ("%s", s) == 1);
    int n = strlen (s);
    s[n] = '+';
    int ans = 0;
    for (int i = 0; i < n; i++)
      ans += s[i] != s[i + 1];
    printf ("Case #%d: %d\n", tt, ans);
  }
  return 0;
}

