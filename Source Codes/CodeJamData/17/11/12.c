#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MOD 1000000007

typedef long long int lld;

char grd[30][30];

int main()
{
  int i, j;
  int t, T;
  scanf("%d", &T);

  for (t = 1; t <= T; t++)
  {
    int w, h;
    scanf("%d %d", &h, &w);

    for (i = 0; i < h; i++)
      scanf(" %s", grd[i]);

    for (i = 0; i < h; i++)
    {
      for (j = 1; j < w; j++)
        if (grd[i][j] == '?')
          grd[i][j] = grd[i][j - 1];
      for (j = w - 2; j >= 0; j--)
        if (grd[i][j] == '?')
          grd[i][j] = grd[i][j + 1];
    }

    for (i = 1; i < h; i++)
    {
      for (j = 0; j < w; j++)
        if (grd[i][j] == '?')
          grd[i][j] = grd[i - 1][j];
    }

    for (i = h - 2; i >= 0; i--)
    {
      for (j = 0; j < w; j++)
        if (grd[i][j] == '?')
          grd[i][j] = grd[i + 1][j];
    }

    for (i = 0; i < h; i++)
      for (j = 0; j < w; j++)
        assert(grd[i][j] != '?');

    printf("Case #%d:\n", t);
    for (i = 0; i < h; i++)
      printf("%s\n", grd[i]);
  }

  return 0;
}
