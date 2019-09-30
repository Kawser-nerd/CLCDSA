#include <stdio.h>

int main ()
{
  int t, i, j, p, cnt = 0;
  long long a, b, l[50];
  for (i = 1; ; i++) {
    p = i;
    for (j = i; j; j /= 10) p = p * 10 + j % 10;
    b = 0;
    for (a = p * (long long) p; a; a /= 10) b = b * 10 + a % 10;
    if (p <= 10000000 && b == p * (long long) p) l[cnt++] = b;
    p = i;
    for (j = i / 10; j; j /= 10) p = p * 10 + j % 10;
    if (p > 10000000) break;
    b = 0;
    for (a = p * (long long) p; a; a /= 10) b = b * 10 + a % 10;
    if (p <= 10000000 && b == p * (long long) p) l[cnt++] = b;
  }
  scanf ("%d", &t);
  for (i = 1; i <= t; i++) {
    scanf ("%lld%lld", &a, &b);
    p = 0;
    for (j = 0; j < cnt; j++) if (a <= l[j] && l[j] <= b) p++;
    printf ("Case #%d: %d\n", i, p);
  }
  return 0;
}
