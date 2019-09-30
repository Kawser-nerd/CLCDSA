#include <stdio.h>
#include <stdlib.h>

#define MaxN 100010

typedef struct
{
      long long x, y;
} tree_t;

int cmp (const void *a, const void *b)
{
   tree_t *x = (tree_t *) a;
   tree_t *y = (tree_t *) b;

   if (x->x > y->x)
      return 1;
   if (x->x < y->x)
      return -1;
   if (x->y > y->y)
      return 1;
   if (x->y < y->y)
      return -1;
   return 0;
}

int main ()
{
   tree_t tree[MaxN];
   int t, testCase, p1, p2, q1, q2, s1, s2, x, y, s;
   long long i, n, A, B, C, D, M, sols[3][3], sol;

   scanf("%d\n", &t);
   for (testCase = 1; testCase <= t; testCase++)
   {
      for (x = 0; x < 3; x++)
         for (y = 0; y < 3; y++)
            sols[x][y] = 0;

      scanf("%lld %lld %lld %lld %lld %lld %lld %lld\n", &n, &A, &B, &C, &D, &tree[0].x, &tree[0].y, &M);

      for (i = 1; i < n; i++)
      {
         tree[i].x = (A*tree[i-1].x+B)%M;
         tree[i].y = (C*tree[i-1].y+D)%M;
      }

      for (i = 0; i < n; i++)
      {
         tree[i].x %= 3;
         tree[i].y %= 3;
      }
      for (i = 0; i < n; i++)
         sols[tree[i].x][tree[i].y]++;

      sol = 0;
      for (x = 0; x < 8; x++)
      {
         for (y = x + 1; y < 9; y++)
         {
            p1 = x / 3;
            p2 = x % 3;
            q1 = y / 3;
            q2 = y % 3;
            s1 = (9-p1-q1)%3;
            s2 = (9-p2-q2)%3;
            s = 3*s1 + s2;
            if (s <= y)
               continue;
            sol += sols[p1][p2]*sols[q1][q2]*sols[s1][s2];
         }
      }
      for (x = 0; x < 9; x++)
      {
         p1 = x / 3;
         p2 = x % 3;
         sol += sols[p1][p2]*(sols[p1][p2]-1)*(sols[p1][p2]-2)/6;

      }

      printf("Case #%d: %lld\n", testCase, sol);
   }
   return 0;
}
