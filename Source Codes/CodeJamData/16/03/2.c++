#include <cassert>
#include <cstdio>
#include <cstring>

//*
const int maxn = 10000000;
long long pd[maxn];
long long pp[maxn], pn;
// */

int divisor ( long long x ) {
  for (long long d = 2; d * d <= x; d++) {
    if (x % d == 0)
      return d;
  }
  return 0;
}

int main () {
  //*
  memset (pd, 0, sizeof (pd));
  pn = 0;
  for (int p = 2; p < maxn; p++) {
    if (pd[p] == 0) {
      pp[pn++] = p;
      pd[p] = p;
    }
    for (int i = 0; i < pn && pp[i] <= pd[p] && (long long)p * pp[i] < maxn; i++)
      pd[p * pp[i]] = pp[i];
  }
  for (int i = 0; i < maxn; i++)
    printf ("%lld\n", pd[i]);
  return 0;
  // */

  int tn;
  assert (scanf ("%d", &tn) == 1);
  assert (tn == 1);
  int n, j;
  assert (scanf ("%d%d", &n, &j) == 2);
 
  long long ans[j];
  long long res[j][11];
  int ansk = 0;
  long long x = (1 << (n - 1)) + 1;
  for (; ansk < j; x += 2) {
    bool ok = true;
    for (int base = 2; base <= 10; base++) {
      long value = 0;
      for (int i = n - 1; i >= 0; i--)
        value = value * base + (x >> i) % 2;
      res[ansk][base] = divisor (value);
      if (!res[ansk][base]) {
        ok = false;
        break;
      }
    }
    if (!ok)
      continue;
    ans[ansk++] = x;
  }

  puts ("Case #1:");
  for (int i = 0; i < ansk; i++) {
    for (int j = n - 1; j >= 0; j--)
      printf ("%lld", (ans[i] >> j) % 2);
    for (int j = 2; j <= 10; j++)
      printf (" %lld", res[i][j]);
    puts ("");
  }

  return 0;
}

