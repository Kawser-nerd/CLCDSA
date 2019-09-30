#include <stdio.h>

int i, C;

char val [100];

int main()
{
  scanf ("%d", &C);

  for (i = 1; i <= C; i++)
    {
      scanf ("%s", val);

      printf ("Case #%d: %s\n", i, val);
    }
}
