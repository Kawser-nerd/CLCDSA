#include <stdio.h>
#include <math.h>

typedef struct
{
  int x;
  double d;
} bound;

bound up[100], low[100];
bound cake[200];
int cak;

double boo(double min, double max, double eat)
{
  while(max - min > 1e-7)
  {
    double cur = (max + min)/2;
    double val = 0;
    int i;
    for (i=1; i<cak && cake[i].x < cur; i++)
      val += (cake[i].x - cake[i-1].x)*(cake[i].d + cake[i-1].d);

    double v = cake[i-1].d + (cake[i].d - cake[i-1].d)*(cur - cake[i-1].x)/(cake[i].x - cake[i-1].x);
    val += (cur - cake[i-1].x)*(cake[i-1].d + v);
    if (val < eat)
      min = cur;
    else
      max = cur;
  }
  return min;
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int t=1; t<=T; t++)
  {
    int W, L, U, G;
    scanf("%d %d %d %d", &W, &L, &U, &G);
    double total = 0;
    for (int i=0; i<L; i++)
    {
      scanf("%d %lf", &low[i].x, &low[i].d);
      if (i > 0)
        total -= (low[i].x - low[i-1].x)*(low[i].d + low[i-1].d);
    }
    for (int i=0; i<U; i++)
    {
      scanf("%d %lf", &up[i].x, &up[i].d);
      if (i > 0)
        total += (up[i].x - up[i-1].x)*(up[i].d + up[i-1].d);
    }

    cake[0].x = 0;
    cake[0].d = up[0].d - low[0].d;
    int ll = 1, uu = 1;
    cak = 1;
    while(ll < L || uu < U)
    {
      int mx = 1001;
      if (ll < L && low[ll].x < mx)
        mx = low[ll].x;
      if (uu < U && up[uu].x < mx)
        mx = up[uu].x;
      cake[cak].x = mx;
      
      double u, l;
      if (ll < L && low[ll].x == mx)
      {
        l = low[ll].d;
        ll++;
      }
      else
        l = low[ll-1].d + (mx - low[ll-1].x)*(low[ll].d - low[ll-1].d)/(low[ll].x - low[ll-1].x);

      if (uu < U && up[uu].x == mx)
      {
        u = up[uu].d;
        uu++;
      }
      else
        u = up[uu-1].d + (mx - up[uu-1].x)*(up[uu].d - up[uu-1].d)/(up[uu].x - up[uu-1].x);
      cake[cak].d = u - l;
      cak++;
    }
    printf("Case #%d:\n", t);
    
    for (int g = 1; g < G; g++)
      printf("%f\n", boo(0, W, g * total / G));
  }
  return 0;
}
