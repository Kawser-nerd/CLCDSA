/*
 * Mark H. Weaver <mhw@netris.org>
 * Code Jam Qualification Round 2012
 * Hall of Mirrors
 * GCC 4.6
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define MIRROR '#'
#define EMPTY  '.'
#define HOME   'X'

#define LIKELY(x)   (__builtin_expect((x), 1))
#define UNLIKELY(x) (__builtin_expect((x), 0))

static int
gcd (int u, int v)
{
  u = abs (u);
  v = abs (v);

  if (UNLIKELY (u == 0))
    return v;
  else if (UNLIKELY (v == 0))
    return u;
  else
    {
      int k = 0;

      /* Determine a common factor 2^k */
      while (((u | v) & 1) == 0)
        {
          k++;
          u >>= 1;
          v >>= 1;
        }

      /* Now, any factor 2^n can be eliminated */
      if ((u & 1) == 0)
        while ((u & 1) == 0)
          u >>= 1;
      else
        while ((v & 1) == 0)
          v >>= 1;

      /* Both u and v are now odd.  Subtract the smaller one
         from the larger one to produce an even number, remove
         more factors of two, and repeat. */
      while (u != v)
        {
          if (u > v)
            {
              u -= v;
              while ((u & 1) == 0)
                u >>= 1;
            }
          else
            {
              v -= u;
              while ((v & 1) == 0)
                v >>= 1;
            }
        }
      return u << k;
    }
}

/* returns 0 or 1 */
static int
see_myself_horiz_p (char *p, int p_incr, int D)
{
  int dist = 1;

  assert (*p == HOME);
  while (p[p_incr] != MIRROR)
    {
      p += p_incr;
      dist += 2;
    }
  return (D >= dist);
}

/* 0 < a <= b <= D and gcd(a,b) == 1.  returns 0 or 1. */
static int
see_myself_p (char *p, int px_incr, int py_incr, int a, int b, int D)
{
  /* We use a coordinate system that allows us to use integers instead
     of rationals, and in which the slope of our line is 1. */

  int x = a+a;  /* 2*a units per grid square */
  int y = b+a;  /* 2*b units per grid square */
  int dist = a; /* distance along one axis in our coordinate system */
  int D_sqr = D*D;
  int D_x = 2*a*D;

  assert (*p == HOME);
  for (;;)
    {
      /* Here we do a fast but imprecise distance check. */
      /* We'll do a precise distance check when we hit home. */
      if (dist > D_x)
        return 0;

      /* (x,y) is on at least one grid line; handle reflections and/or
         translations of our coordinate system as needed, so that
         either x or y is reset to 0, and so that both x and y are
         monotonically non-decreasing, for code simplicity. */
      if (LIKELY (y < 2*b))
        {
          /* We hit a vertical grid line */
          if (p[px_incr] == MIRROR)
            px_incr = -px_incr;  /* Flip map horizontally */
          else
            p += px_incr;  /* Translate map horizontally */
          x = 0;
        }
      else if (LIKELY (y > 2*b))
        {
          /* We passed a horizontal grid line; back up to it */
          int delta = y - 2*b;

          y -= delta;
          x -= delta;
          dist -= delta;
          if (p[py_incr] == MIRROR)
            py_incr = -py_incr;  /* Flip map vertically */
          else
            p += py_incr;  /* Translate map vertically */
          y = 0;
        }
      else
        {
          /* Hit intersection of grid lines */
          if (p[px_incr + py_incr] != MIRROR)
            p += px_incr + py_incr;  /* Translate map diagonally */
          else if (p[px_incr] == MIRROR &&
                   p[py_incr] == MIRROR)
            {
              /* Hit inside corner, so we reflect back to home by the
                 same path we took. */

              int dist_x, dist_y;  /* Integral grid units */

              dist += dist;  /* Double the distance */

              /* Do precise distance check */
              assert (dist % (2*a) == 0);
              assert (dist % (2*b) == 0);
              dist_x = dist / (2*a);
              dist_y = dist / (2*b);
              return (D_sqr >= dist_x * dist_x + dist_y * dist_y);
            }
          else if (p[px_incr] == MIRROR)
            {
              p += py_incr;        /* Translate map vertically */
              px_incr = -px_incr;  /* Flip map horizontally */
            }
          else if (p[py_incr] == MIRROR)
            {
              p += px_incr;        /* Translate map horizontally */
              py_incr = -py_incr;  /* Flip map vertically */
            }
          else
            return 0;  /* Ray destroyed by hitting corner */
          x = y = 0;
        }

      if (UNLIKELY (*p == HOME) && x == 0 && UNLIKELY (y == b-a))
        {
          /* Hit home */
          int dist_x, dist_y;  /* Integral grid units */

          /* Do precise distance check */
          dist += a;
          assert (dist % (2*a) == 0);
          assert (dist % (2*b) == 0);
          dist_x = dist / (2*a);
          dist_y = dist / (2*b);
          
          return (D_sqr >= dist_x * dist_x + dist_y * dist_y);
        }

      /* Advance to next vertical grid line.  Note that we may cross a
         horizontal grid line here, but if so we'll fix that up later,
         at the top of the loop.  We do it this way to simplify
         initialization, and also because we cross vertical grid lines
         at least as often as horizontal grid lines. */
      {
        int delta = 2*a - x;

        x += delta;
        y += delta;
        dist += delta;
      }
    }
}

static char *
find_home (char *map, int H, int W)
{
  char *p = map + H*W;

  while (--p >= map)
    if (*p == HOME)
      return p;
  assert (0);
}

static int
count_self_images (char *map, int H, int W, int D)
{
  char *p = find_home (map, H, W);
  int count = 0;
  int a, b;

  count += see_myself_horiz_p (p, +1, D);      /* east */
  count += see_myself_horiz_p (p, -1, D);      /* west */
  count += see_myself_horiz_p (p, -W, D);      /* north */
  count += see_myself_horiz_p (p, +W, D);      /* south */

  count += see_myself_p (p, +1, -W, 1, 1, D);  /* north-east */
  count += see_myself_p (p, -1, +W, 1, 1, D);  /* south-west */
  count += see_myself_p (p, -W, -1, 1, 1, D);  /* north-west */
  count += see_myself_p (p, +W, +1, 1, 1, D);  /* south-east */

  for (a = 1; a < D; a++)
    for (b = a + 1; b <= D; b++)
      if (gcd (a, b) == 1 && D*D >= a*a + b*b)
        {
          count += see_myself_p (p, +1, -W, a, b, D);  /* east-north-east */
          count += see_myself_p (p, -W, +1, a, b, D);  /* north-north-east */
          count += see_myself_p (p, -1, +W, a, b, D);  /* west-south-west */
          count += see_myself_p (p, +W, -1, a, b, D);  /* south-south-west */
          count += see_myself_p (p, -1, -W, a, b, D);  /* west-north-west */
          count += see_myself_p (p, -W, -1, a, b, D);  /* north-north-west */
          count += see_myself_p (p, +1, +W, a, b, D);  /* east-south-east */
          count += see_myself_p (p, +W, +1, a, b, D);  /* south-south-east */
        }

  return count;
}

static void
process_one_case (int case_num, int H, int W, int D)
{
  char *map = malloc (H*W+1);
  char *p = map;
  int i;

  for (i = 0; i < H; i++)
    {
      scanf ("%s ", p);
      p += W;
    }

  printf ("Case #%d: %d\n", case_num, count_self_images (map, H, W, D));

  free (map);
}

int
main ()
{
  int T, i;

  scanf ("%d ", &T);
  for (i = 1; i <= T; i++)
    {
      int H, W, D;

      scanf ("%d %d %d ", &H, &W, &D);
      process_one_case (i, H, W, D);
    }
  return 0;
}

