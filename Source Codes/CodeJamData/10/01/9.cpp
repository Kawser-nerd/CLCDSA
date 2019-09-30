#include <cstdio>
#include <cmath>

using namespace std;

int
main(void)
{
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; t++)
    {
      int N, K;
      long long int n, k;
      scanf("%d%d", &N, &K);
      n = N;
      k = K;
      if ((k+1) % ((long long int)1 << n) == 0)
        printf("Case #%d: ON\n", t+1);
      else
        printf("Case #%d: OFF\n", t+1);
    }
  return 0;
}
