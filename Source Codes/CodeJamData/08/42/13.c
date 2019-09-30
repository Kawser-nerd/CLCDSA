#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int N, M, A, C, i0, i1, i2, j0, j1, j2, s, n, flag;
  scanf(" %d", &C);
  for(n = 0; n < C; n++)
    {
      scanf(" %d %d %d", &N, &M, &A);
      flag = 0;
      for(i0 = 0; i0 <= N; i0++)
        for(j0 = 0; j0 <= M; j0++)
          for(i1 = i0; i1 <= N; i1++)
            for(j1 = 0; j1 <= M; j1++)
              for(i2 = i1; i2 <= N; i2++)
                for(j2 = 0; j2 <= M; j2++)
                  {
                    s = (i1 - i0) * (j2 - j0) - (i2 - i0) * (j1 - j0);
                    if(s == A)
                      {
                        printf("Case #%d: %d %d %d %d %d %d\n", n + 1, i0, j0, i1, j1, i2, j2);
                        goto end;
                      }
                  }
      printf("Case #%d: IMPOSSIBLE\n", n + 1);
    end:;
    }
  return 0;
}

