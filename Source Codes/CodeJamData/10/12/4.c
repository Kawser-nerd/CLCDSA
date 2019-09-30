#include <stdio.h>
#include <stdlib.h>


int min(int a, int b)
{
  return a < b ? a : b;
}

int max(int a, int b)
{
  return a > b ? a : b;
}

int main()
{
  int T, C, D, I, M, N;
  scanf("%d", &T);

  for (C = 1; C <= T; ++C)
  {
    scanf("%d %d %d %d", &D, &I, &M, &N);

    int r[256], nr[256];
    int i, j, q;

    memset(r, 0, sizeof(r));

    while (N-- > 0)
    {
      for (i = 0; i < 256; ++i)
        nr[i] = r[i] + D;

      scanf("%d", &q);

      if (M == 0)
        for (i = 0; i < 256; ++i)
          nr[i] = min(nr[i], r[i] + abs(q - i));
      else
        for (i = 0; i < 256; ++i)
          for (j = 0; j < 256; ++j)
            nr[j] = min(nr[j], r[i] + abs(q - j) + (max(0, abs(i - j) - 1) / M) * I);

      memcpy(r, nr, sizeof(r));
    }

    q = 1000000;

    for (i = 0; i < 256; ++i)
      q = min(q, r[i]);

    printf("Case #%d: %d\n", C, q);
  }

  return 0;
}
