#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int T, t;
  scanf("%d", &T);

  for(t = 1; t <= T; t++)
  {
    int N;
    scanf("%d", &N);

    int A[1001], B[1001];
    int i;
    for(i = 0; i < N; i++)
      scanf("%d %d", &A[i], &B[i]);

    int stars[1001] = {0};
    int totalstars = 0;
    int completed = 0;
    while(totalstars < N*2)
    {
      int prevstars = totalstars;
      int best = -1, besti = -1;
      for(i = 0; i < N; i++)
      {
        if(stars[i] < 2 && totalstars >= B[i])
        {
          totalstars += 2 - stars[i];
          stars[i] = 2;
          completed++;
          //printf("%d ==> 2 (%d)\n", i, totalstars);
        }
        else if(stars[i] == 0 && totalstars >= A[i] && B[i] > best)
        {
          best = B[i];
          besti = i;
        }
      }

      if(totalstars == prevstars)
      {
        if(besti == -1)
        {
          completed = -1;
          break;
        }
        else
        {
          stars[besti] = 1;
          totalstars++;
          completed++;
          //printf("%d ==> 1 (%d)\n", besti, totalstars);
        }
      }
    }

    if(completed == -1)
      printf("Case #%d: Too Bad\n", t);
    else
      printf("Case #%d: %d\n", t, completed);
  }
  
  return 0;
}
