/*
 * Mark H. Weaver <mhw@netris.org>
 * Code Jam Qualification Round 2012
 * Recycled Numbers
 * GCC 4.6
 */

#include <stdio.h>

#define LIKELY(x)   (__builtin_expect((x), 1))
#define UNLIKELY(x) (__builtin_expect((x), 0))

static int
num_bcd_digits (int x)
{
  int i = 0;

  while (x != 0)
    {
      x >>= 4;
      i++;
    }
  return i;
}

static int
increment_bcd (int x)
{
  if (LIKELY ((x & 0xf) != 9))
    return x + 1;
  else
    return increment_bcd (x >> 4) << 4;
}

static int
count_recycled (int a, int b, int num_rotations)
{
  int found[num_rotations];
  int shift = 4 * num_rotations;
  int total_found = 0;
  int n;

  for (n = a; n < b; n = increment_bcd (n))
    {
      int num_found = 0;
      int m = n;
      int i;

      for (i = num_rotations; i != 0; i--)
        {
          m = (m >> 4) | ((m & 0xf) << shift);
          if (n < m && m <= b)
            {
              int j;

              for (j = num_found - 1; j >= 0; j--)
                if (UNLIKELY (m == found[j]))
                  break;

              if (j < 0)
                {
                  found[num_found++] = m;
                  total_found++;
                }
            }
        }
    }
  return total_found;
}

int main ()
{
  int T, i;

  scanf ("%d", &T);
  for (i = 1; i <= T; i++)
    {
      int a, b;

      scanf (" %x %x", &a, &b);
      printf ("Case #%d: %d\n", i, count_recycled (a, b, num_bcd_digits (a) - 1));
    }
  return 0;
}

