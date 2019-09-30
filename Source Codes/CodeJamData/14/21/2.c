#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int intcmp(const void *v1, const void *v2)
{
  return *(const int *)v1 - *(const int *)v2;
}

char strs[100][101];
char *ptrs[100];

int main(void)
{
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++)
  {
    int N;
    scanf("%d", &N);

    int i;
    for (i = 0; i < N; i++)
    {
      scanf("%s", strs[i]);
      ptrs[i] = strs[i];
    }

    int total = 0;
    while (1)
    {
      int counts[100] = {0};
      char c = *ptrs[0];
      for (i = 0; i < N; i++)
      {
        //printf("ptrs[%d] = %s\n", i, ptrs[i]);
        if (*ptrs[i] != c)
        {
          printf("Case #%d: Fegla Won\n", t);
          goto next;
        }

        while (*++ptrs[i] == c)
          counts[i]++;
      }

      if (c == 0)
        break;

      qsort(counts, N, sizeof(int), &intcmp);
      int median = counts[N / 2];
      for (i = 0; i < N; i++)
        total += abs(counts[i] - median);
    }

    printf("Case #%d: %d\n", t, total);

  next:
    ;
  }

  return 0;
}
