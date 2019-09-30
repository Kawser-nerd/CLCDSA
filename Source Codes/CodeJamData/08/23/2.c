#include <stdio.h>
#include <stdlib.h>

int main ()
{
   int t, testCase, i, c, k, num, card[6000], n, count;
   scanf("%d\n", &t);
   for (testCase = 1; testCase <= t; testCase++)
   {
      scanf("%d\n", &k);

      for (i = 1; i <= k; i++)
         card[i] = 0;

      i = 1;
      for (c = 1; c <= k; c++)
      {
         count = 0;
         while (1)
         {
            if (card[i] != 0)
            {
               i++;
               if (i == k+1)
                  i = 1;
               continue;
            }

            count++;
            if (count == c)
            {
               card[i] = c;
               break;
            }
            i++;
            if (i == k + 1)
               i = 1;
         }
      }
      scanf("%d", &n);
      printf("Case #%d:", testCase);
      for (i = 0; i < n; i++)
      {
         scanf("%d", &num);
         printf(" %d", card[num]);
      }
      printf("\n");
   }

   return 0;
}
