#include <stdio.h>
#include <string.h>

#define MOD 1000000007

typedef long long int lld;

int mp[50][50];

inline int min(int a, int b)
{
  return (a < b) ? a : b;
}

int calc(int mask, int w, int h)
{
  int i, j;
  for (i = 0; i < h; i++)
    for (j = 0; j < w; j++)
      mp[i][j] = (mask & (1 << (j + i * w))) > 0;

  int vl = 0;
  for (i = 0; i < h; i++)
    for (j = 0; j < w; j++)
      if (mp[i][j])
        vl += mp[i][j + 1] + mp[i + 1][j];
  return vl;
}

int main()
{
  int i;
  int t, T;

  scanf("%d", &T);

  for (t = 1; t <= T; t++)
  {
    int r, c, n = 0;
    scanf("%d %d %d", &r, &c, &n);
    memset(mp, 0, sizeof mp);

    int mn = r * c * n;
    for (i = 0; i < (1 << (r * c)); i++)
      if (__builtin_popcount(i) == n)
        mn = min(mn, calc(i, c, r));

    printf("Case #%d: %d\n", t, mn);
  }

  return 0;
}
