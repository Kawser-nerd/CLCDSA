#include <string.h>
#include <stdio.h>

int p, pp;
int m[1024];
int c[11][1024];
long long cc[11][1024][11];

long long min(long long a, long long b)
{
  if (a < b)
    return a;
  return b;
}

int main()
{
  int t, T;
  scanf("%d ", &T);
  for(t = 1; t <= T; ++t)
  {
    memset(cc, 0, sizeof(cc));
    scanf("%d ", &p);
    pp = 1 << p;

    int i, j, k;

    for(i = 0; i < pp; ++i)
      scanf("%d ", &m[i]);

    int w = pp;

    for(i = 1; i <= p; ++i)
    {
      w /= 2;
      for (j = 0; j < w; ++j)
        scanf("%d ", &c[i][j]);
    }

    for(i = 0; i < pp; ++i)
      for(j = m[i] + 1; j <= p; ++j)
        cc[0][i][j] = 1000000000000L;

    w = pp;

    for(i = 1; i <= p; ++i)
    {
      w /= 2;
      for(j = 0; j < w; ++j)
      {
        for(k = 0; k <= p; ++k)
          cc[i][j][k] = cc[i - 1][2 * j][k] + cc[i - 1][2 * j + 1][k] + c[i][j];
        for(k = 0; k < p; ++k)
          cc[i][j][k] = min(cc[i][j][k], cc[i - 1][2 * j][k + 1] + cc[i - 1][2 * j + 1][k + 1]);
      }
    }

    printf("Case #%d: %lld\n", t, cc[p][0][0]);
  }
}

