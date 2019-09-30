#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 500
#define INFINITY 2000000000

int Compute (int a[MAXN][MAXN], int sum[MAXN], int l, int r)
{
     if (a[l][r] > -1) return a[l][r];
     if (l == r)
     {
          a[l][r] = 0;
          return 0;
     }
     int i;
     int min = INFINITY;
     int temp;
     for (i = l+1; i <= r; i += 2)
     {
          temp = Compute(a,sum,l,i-1) + Compute(a,sum,i+1,r);
          if (temp < min) min = temp;
     }
     a[l][r] = (sum[r] - sum[l-1] - 1) + min;
     return a[l][r];
}

int main ()
{
     int T, iT;
     scanf("%d",&T);
     int N, P, comp, last, pos, i, j;
     static int data[MAXN];
     static int sum[MAXN];
     static int a[MAXN][MAXN];
     for (iT = 0; iT < T; iT++)
     {
          scanf("%d %d",&N,&P);
          comp = 0;
          pos = 1;
          for (i = 0; i < P; i++)
          {
               scanf("%d",&last);
               data[pos] = last - comp - 1;
               pos++;
               data[pos] = 1;
               pos++;
               comp = last;
          }
          data[pos] = N - comp;
          pos++;
          
          sum[0] = 0;
          for (i = 1; i < pos; i++)
          {
               sum[i] = sum[i-1] + data[i];
          }
          
          for (i = 0; i < MAXN; i++)
          {
               for (j = 0; j < MAXN; j++)
               {
                    a[i][j] = -1;
               }
          }
          
          printf("Case #%d: %d\n",iT+1,Compute(a,sum,1,pos-1));
     }
     return 0;
}
