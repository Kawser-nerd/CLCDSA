#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ()
{
     int T, iT;
     scanf("%d\n",&T);
     char data[30];
     int left[12];
     int N, i, j, prev;
     for (iT = 0; iT < T; iT++)
     {
          gets(&(data[1]));
          data[0] = '0';
          N = strlen(data);
          memset(left,0,sizeof(left));
          for (i = 0; i < N; i++)
          {
               data[i] -= '0';
          }
          
          prev = -1;
          i = N-1;
          while (1)
          {
               left[(int)(data[i])]++;
               if (data[i] < prev) break;
               prev = data[i];
               i--;
          }
          j = data[i]+1;
          while (left[j] == 0) j++;
          data[i] = j;
          left[(int)(j)]--;
          i++;
          j = 0;
          while (i < N)
          {
               while (left[j] == 0) j++;
               data[i] = j;
               left[j]--;
               i++;
          }
          printf("Case #%d: ",iT+1);
          i = 0;
          if (data[i] == 0) i++;
          while (i < N)
          {
               printf("%d",data[i]);
               i++;
          }
          printf("\n");
     }
     return 0;
}
