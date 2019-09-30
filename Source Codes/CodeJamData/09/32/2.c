#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 505
#define EPSILON 1E-9

struct point
{
     int x, y, z, vx, vy, vz;
};

struct vec
{
     double x0, vx, y0, vy, z0, vz;
};

struct vec GetVec (struct point a[MAXN], int N)
{
     struct vec res;
     int i;
     int sumx = 0;
     int sumy = 0;
     int sumz = 0;
     for (i = 0; i < N; i++)
     {
          sumx += a[i].x;
          sumy += a[i].y;
          sumz += a[i].z;
     }
     res.x0 = (double)(sumx) / (double)(N);
     res.y0 = (double)(sumy) / (double)(N);
     res.z0 = (double)(sumz) / (double)(N);
     sumx = 0;
     sumy = 0;
     sumz = 0;
     for (i = 0; i < N; i++)
     {
          sumx += (a[i].x + a[i].vx);
          sumy += (a[i].y + a[i].vy);
          sumz += (a[i].z + a[i].vz);
     }
     res.vx = (double)(sumx) / (double)(N);
     res.vy = (double)(sumy) / (double)(N);
     res.vz = (double)(sumz) / (double)(N);     
     res.vx -= res.x0;
     res.vy -= res.y0;
     res.vz -= res.z0;
     return res;
}

double GetDist (struct vec a, double t)
{
     double x, y, z;
     x = a.x0 + a.vx * t;
     y = a.y0 + a.vy * t;
     z = a.z0 + a.vz * t;
     if (x < 0) x *= -1;
     if (y < 0) y *= -1;
     if (z < 0) z *= -1;
     double res = sqrt(x*x + y*y + z*z);
     return res;
}

int main ()
{
     int T, iT;
     scanf("%d",&T);
     int N, i;
     static struct point a[MAXN];
     struct vec ln;
     double l, r, c1, c2;
     double lv, rv, c1v, c2v;
     char ta, tb, tc;
     for (iT = 0; iT < T; iT++)
     {
          scanf("%d",&N);
          for (i = 0; i < N; i++) scanf("%d %d %d %d %d %d",&(a[i].x),&(a[i].y),&(a[i].z),&(a[i].vx),&(a[i].vy),&(a[i].vz));
          ln = GetVec(a,N);
          l = 0.0; r = 2500020.0;
          lv = GetDist(ln,l);
          rv = GetDist(ln,r);
          while ((r-l) > EPSILON)
          {
               //printf("(%.8f ; %.8f)\n",l,r);
               c1 = l + ((r-l)/3);
               c2 = r - ((r-l)/3);
               c1v = GetDist(ln,c1);
               c2v = GetDist(ln,c2);
               if (c1v < lv) ta = 0; else ta = 1;
               if (c2v < c1v) tb = 0; else tb = 1;
               if (rv < c2v) tc = 0; else tc = 1;
               if (ta)
               {
                    r = c1;
                    rv = c1v;
               }
               else if (tb)
               {
                    r = c2;
                    rv = c2v;
               }
               else if (tc)
               {
                    l = c1;
                    lv = c1v;
               }
               else
               {
                    l = c2;
                    lv = c2v;
               }
          }
          c1 = (l+r)/2;
          c1v = GetDist(ln,c1);
          printf("Case #%d: %.8f %.8f\n",iT+1,c1v,c1);
     }
     return 0;
}
