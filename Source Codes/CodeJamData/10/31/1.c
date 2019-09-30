#include<stdio.h>
#include<stdlib.h>

int ropes[1000][2];

int main()
{
  int T;
  scanf("%d",&T);

  for(int times = 1; times <= T; times++)
    {
      int N;
      scanf("%d",&N);

      int ints = 0;

      for(int i = 0; i < N; i++)
	{
	  scanf("%d %d",&ropes[i][0],&ropes[i][1]);

	  for(int j = 0; j < i; j++)
	    {
	      if((ropes[j][0] < ropes[i][0] && ropes[j][1] > ropes[i][1])
		 || (ropes[j][0] > ropes[i][0] && ropes[j][1] < ropes[i][1]))
		ints++;
	    }
	}

      printf("Case #%d: %d\n",times, ints);
    }

  return 0;
}
