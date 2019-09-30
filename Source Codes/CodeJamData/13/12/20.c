#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long acts[10000];
long long E;
long long R;
int N;

long long max_gain(int now_e, int nthact)
{
     long long p, max;
     int i;
     
     if (nthact == N)
	  return 0;
     if (now_e > E)
	  now_e = E;
     max = 0;
     for (i = 0; i <= now_e; i++) {
	  p = max_gain(now_e-i+R, nthact+1) + i * acts[nthact];
	  if (p > max)
	       max = p;
     }

     return max;
}

int main(void)
{
     int T;
     int nc;
     long long max;
     int i;
     
     scanf("%d", &T);
     for (nc = 1; nc <= T; nc++) {
	  scanf("%lld%lld%d", &E, &R, &N);
	  for (i = 0; i < N; i++)
	       scanf("%lld", &acts[i]);
	  max = max_gain(E, 0);
	  printf("Case #%d: %lld\n", nc, max);
     }

     return 0;
}
	  
     
