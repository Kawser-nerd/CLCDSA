#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN 70

int main ()
{
     int T, iT;
     scanf("%d\n",&T);
     static int a[256];
     int N, i, cur;
     char data[MAXLEN];
     long long int res, coef;
     for (iT = 0; iT < T; iT++)
     {
          printf("Case #%d: ",iT+1);
          gets(data);
          N = strlen(data);
          for (i = 0; i < 256; i++) a[i] = -1;
          a[(int)(data[0])] = 1;
          cur = 0;
          for (i = 1; i < N; i++)
          {
               if (a[(int)(data[i])] == -1)
               {
                  a[(int)(data[i])] = cur;
                  cur++;
                  if (cur == 1) cur++;  
               }
          }
          if (cur == 0) cur += 2;
          res = 0;
          coef = 1;
          for (i = N-1; i >= 0; i--)
          {
               res += coef * (long long int)(a[(int)(data[i])]);
               if (i > 0) coef *= cur;
          }
          printf("%lli\n",res);
     }
     return 0;
}
