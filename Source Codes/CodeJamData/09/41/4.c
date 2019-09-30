#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 50

int main ()
{
     int T, iT;
     scanf("%d",&T);
     int N;
     int i, j, k, temp;
     static char data[MAXN][MAXN];
     static int a[MAXN];
     int res;
     for (iT = 0; iT < T; iT++)
     {
          scanf("%d\n",&N);
          for (i = 0; i < N; i++)
          {
               gets(data[i]);
               a[i] = -1;
               for (j = 0; j < N; j++)
               {
                    if (data[i][j] == '1') a[i] = j;
               }
          }
          res = 0;
          for (i = 0; i < N-1; i++)
          {
               if (a[i] > i)
               {
                    j = i;
                    while (a[j] > i) j++;
                    res += (j-i);
                    temp = a[j];
                    for (k = j-1; k >= i; k--) a[k+1] = a[k];
                    a[i] = temp;
               }
          }
          printf("Case #%d: %d\n",iT+1,res);
     }
     return 0;
}
