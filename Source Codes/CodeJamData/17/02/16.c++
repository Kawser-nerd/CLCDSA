#include <cassert>
#include <cstdio>
#include <cstring>

const int maxn = 25;

int main () {
  int tn;
  assert (scanf ("%d", &tn) == 1);
  for (int tt = 1; tt <= tn; tt++) {
    char s[maxn];
    assert (scanf ("%s", s) == 1);
    int n = strlen (s);
    int i = 0;
    while (i < n - 1 && s[i] <= s[i + 1])
      i++;
    if (i == n - 1) {
      printf ("Case #%d: %s\n", tt, s);
      continue;
    }
    while (i > 0 && s[i] == s[i - 1])
      i--;
    s[i]--;
    for (int j = i + 1; j < n; j++)
      s[j] = '9';
    if (s[i] == '0')
      printf ("Case #%d: %s\n", tt, s + 1);
    else
      printf ("Case #%d: %s\n", tt, s);
  }
  return 0;
}

