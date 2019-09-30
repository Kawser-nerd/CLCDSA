#include <stdio.h>

#define MAXN 50

int can[MAXN];
int x[MAXN];
int v[MAXN];

int n, k, b, t;

int work() {
  int swp = 0;
  int cnt;
  int i, j;

  if (k == 0)
    return 0;

  for (i = 0; i < n; ++i)
    if ((b - x[i] + v[i] - 1) / v[i] <= t)
      can[i] = 1;
    else
      can[i] = 0;

  cnt = 0;
  for (j = n - 1; j >= 0; --j) {
    if (can[j])
      ++cnt;

    if (cnt == k)
      break;
  }
  if (cnt < k)
    return -1;

  cnt = 0;
  for (i = j; i < n; ++i) {
    if (can[i])
      ++cnt;
    else
      swp += cnt;
  }

  return swp;
}

int main() {
  int c, i, j, r;

  scanf("%d", &c);
  for (i = 1; i <= c; ++i) {
    scanf("%d %d %d %d", &n, &k, &b, &t);
    for (j = 0; j < n; ++j)
      scanf("%d", x+j);
    for (j = 0; j < n; ++j)
      scanf("%d", v+j);

    printf("Case #%d: ", i);
    r = work();
    if (r < 0)
      printf("IMPOSSIBLE\n");
    else
      printf("%d\n", r);
  }
}
