#include <stdio.h>
#include <string.h>

int main()
{
  int t, T;

  scanf("%d", &T);

  for(t = 1; t <= T; ++t)
  {
    int r;
    int x[100][100];

    scanf("%d ", &r);
    memset(x, 0, sizeof(x));

    int i, j, k;

    for(i = 0; i < r; ++i)
    {
      int x1, y1, x2, y2;

      scanf("%d %d %d %d ", &x1, &y1, &x2, &y2);

      for(j = x1; j <= x2; ++j)
        for(k = y1; k <= y2; ++k)
          x[j - 1][k - 1] = 1;
    }

    int sec = 0;

    while(1)
    {
      int y[100][100];
      memset(y, 0, sizeof(y));
      int mam = 0;

      for(i = 0; i < 100; ++i)
        for(j = 0; j < 100; ++j)
          if(x[i][j])
            mam = 1;

      if(!mam)
        break;

      for(i = 1; i < 100; ++i)
        for(j = 1; j < 100; ++j)
          y[i][j] = (x[i][j] && (x[i - 1][j] || x[i][j - 1])) || (x[i - 1][j] && x[i][j - 1]);

      memcpy(x, y, sizeof(y));
      ++sec;
    }

    printf("Case #%d: %d\n", t, sec);
  }
}

