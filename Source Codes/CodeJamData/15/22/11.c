#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
  int T, t, r, c, n, x, current_unhappiness, i1, j1, i2, j2, best_unhappiness;

  scanf("%d", &T);
  for (t = 1; t <= T; ++t) {
    scanf("%d%d%d", &r, &c, &n);
    best_unhappiness = INT_MAX;
    for (x = 0; x < 1 << (r * c); ++x) {
      if (__builtin_popcount(x) != n)
        continue;
      current_unhappiness = 0;
      for (i1 = 0; i1 < r; ++i1)
        for (j1 = 0; j1 < c; ++j1)
          for (i2 = 0; i2 < r; ++i2)
            for (j2 = 0; j2 < c; ++j2)
              if ((abs(i1 - i2) == 1 && j1 == j2) || (abs(j1 - j2) == 1 && i1 == i2))
                if ((x & 1 << (i1 * c + j1)) && (x & 1 << (i2 * c + j2)))
                  ++current_unhappiness;
      current_unhappiness >>= 1;
      if (current_unhappiness < best_unhappiness)
        best_unhappiness = current_unhappiness;
    }
    printf("Case #%d: %d\n", t, best_unhappiness);
  }
  return 0;
}
