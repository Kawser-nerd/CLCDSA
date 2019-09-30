#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
  int T;
  scanf("%d",&T);

  for(int times = 1; times <= T; times++)
    {
      int L,P,C;

      scanf("%d %d %d",&L,&P,&C);

      double rat = ((double)P)/L;

      double l1 = ceil(log2(rat)/log2(C))+1;
      double l2 = ceil(log2(l1-1));

      printf("Case #%d: %d\n",times,(int)l2);
    }

  return 0;
}

