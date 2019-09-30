#include <stdio.h>
#include <limits.h>

int main()
{
  int t, T, f[1000001], i, x, l, n, k;
  for (i = 1; i <= 1000000; ++i)
    f[i] = INT_MAX;
  f[1] = 1;
  for (i = 1; i <= 999999; ++i) {
    for (k = 1; i / (10 * k) > 0; k *= 10);
    for (l = 1, x = 0; k > 0; x += l * (i / k % 10), k /= 10, l *= 10);
    if (f[i + 1] > f[i] + 1)
      f[i + 1] = f[i] + 1;
    if (x != i && f[x] > f[i] + 1)
      f[x] = f[i] + 1;
  }
  scanf("%d", &T);
  for (t = 1; t <= T; ++t) {
    scanf("%d", &n);
    printf("Case #%d: %d\n", t, f[n]);
  }
  return 0;
}
