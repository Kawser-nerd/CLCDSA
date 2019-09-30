#include <stdio.h>

char str[60];

int main()
{
  int i, j;
  int t, T;
  scanf("%d", &T);

  for (t = 1; t <= T; t++)
  {
    int imp = 0;
    int n, L;
    scanf("%d %d", &n, &L);

    for (i = 0; i < n; i++)
    {
      scanf(" %s", str);

      for (j = 0; str[j]; j++)
        if (str[j] == '0')
          break;
      if (!str[j])
        imp = 1;
    }

    scanf(" %*s");

    printf("Case #%d:", t);

    if (imp)
      printf(" IMPOSSIBLE\n");
    else
    {
      if (L == 1)
      {
        printf(" 0? 0\n");
        continue;
      }

      printf(" ");
      for (i = 0; i < L - 1; i++)
        printf("?");

      printf(" ");
      for (i = 0; i < 30; i++)
        printf("10");
      printf("?");
      for (i = 0; i < 30; i++)
        printf("10");

      printf("\n");
    }
  }
  
  return 0;
}
