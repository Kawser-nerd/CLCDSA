#include <stdio.h>

int chick_pos [51];
int chick_v [51];
int chick_t [51];

int main()
{
  int C;

  int c;

  scanf ("%d", &C);

  for (c = 1; c <= C; c++)
    {
      int N, K, B, T;
      int n, k, swap, w;

      scanf ("%d %d %d %d", &N, &K, &B, &T);

      for (n = 0; n < N; n++)
	scanf ("%d", &chick_pos [n]);

      for (n = 0; n < N; n++)
	scanf ("%d", &chick_v [n]);

      for (n = 0; n < N; n++)
	{
	  int d = B - chick_pos [n];

	  chick_t [n] = d / chick_v [n] + ((d % chick_v [n]) ? 1 : 0);
	}

      k = swap = w = 0;

      for (n = N - 1; n >= 0; n--)
	{
	  if (chick_t [n] <= T)
	    {
	      swap += w;

	      if (++k >= K)
		break;
	    }
	  else 
	      w++;
	}

      if (k >= K)
	printf ("Case #%d: %d\r\n", c, swap);
      else
	printf ("Case #%d: IMPOSSIBLE\r\n", c);
    }
}
