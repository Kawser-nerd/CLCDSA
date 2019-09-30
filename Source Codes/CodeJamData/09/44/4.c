#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 4

struct plant
{
     int x, y, r;
};

int main ()
{
     int T, iT;
     scanf("%d",&T);
     int N;
     int i;
     static struct plant a[MAXN];
     double res;
     double p01, p02, p12;
     for (iT = 0; iT < T; iT++)
     {
          scanf("%d",&N);
          for (i = 0; i < N; i++)
          {
               scanf("%d %d %d",&(a[i].x),&(a[i].y),&(a[i].r));
          }
          if (N == 1)
          {
               res = (double)(a[0].r);
          }
          else if (N == 2)
          {
               if (a[0].r > a[1].r) res = (double)(a[0].r);
               else res = (double)(a[1].r);
          }
          else if (N == 3)
          {
               p01 = sqrt((double)((a[1].x - a[0].x) * (a[1].x - a[0].x) + (a[1].y - a[0].y) * (a[1].y - a[0].y))) + (double)(a[0].r + a[1].r);
               p02 = sqrt((double)((a[2].x - a[0].x) * (a[2].x - a[0].x) + (a[2].y - a[0].y) * (a[2].y - a[0].y))) + (double)(a[0].r + a[2].r);
               p12 = sqrt((double)((a[1].x - a[2].x) * (a[1].x - a[2].x) + (a[1].y - a[2].y) * (a[1].y - a[2].y))) + (double)(a[1].r + a[2].r);
               res = p01;
               if (p02 < res) res = p02;
               if (p12 < res) res = p12;
               res /= 2.0;
          }
          else res = 0.0;
          printf("Case #%d: %.9lf\n",iT+1,res);
     }
     return 0;
}
