#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int num_a, num_q;
int as[40000];

int main()
{
  scanf("%d %d", &num_a, &num_q);
  for (int i = 0; i < num_a; ++i)
  {
    int y;
    scanf("%d", &y);
    as[i] = y;
  }
  for (int i = 0; i < num_q; ++i)
  {
    int l, r, x, y;
    scanf("%d %d %d %d", &l, &r, &x, &y);
    int c = 0;
    for (int j = l; j <= r; ++j)
    {
      if (as[j] % x == y)
      {
        c++;
      }
    }
    printf("%d\n", c);
  }
  return 0;
}
