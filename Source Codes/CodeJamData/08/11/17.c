#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <algorithm>

using namespace std;

int main(void)
{
  int N, M;
  int n, i, d, u, k, m, x[1000], y[1000];
  long long sum;
  
  scanf(" %d", &N);
  for(n = 0; n < N; n++)
    {
      scanf(" %d", &M);
      for(i = 0; i < M; i++)
        {
          scanf(" %d", x + i);
        }
      for(i = 0; i < M; i++)
        {
          scanf(" %d", y + i);
        }
      sort(x, x + M);
      sort(y, y + M);
      
      sum = 0;
      d = 0;
      while(x[d] < 0 && y[M - d - 1] > 0)
        {
          sum += x[d] * y[M - d - 1];
          d++;
        }
      u = M - 1;
      while(x[u] > 0 && y[M - u - 1] < 0)
        {
          sum += x[u] * y[M - u - 1];
          u--;
        }
      for(k = d; k <= u; k++)
        {
          sum += x[k] * y[M - k - 1];
          assert(x[k] * y[M - k - 1] >= 0);
        }
      printf("Case #%d: %d\n", n + 1, sum);
      
    }
  return 0;
}
