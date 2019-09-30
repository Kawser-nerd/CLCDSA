#include <stdio.h>

int h[2001];
int y[2001];
int N;

int process(int d, int cur, int locmax)
{
  if (cur == N)
  {
    y[cur] = 0;
    return 1;
  }
  if (cur >= locmax)
    return 1;
  int next = h[cur];
  if (next > locmax)
    return 0;
  if (process(d, next, locmax) == 0)
    return 0;
  if (process(d+1, cur+1, next) == 0)
    return 0;
  y[cur] = y[next] - (next - cur)*d;
  return 1;
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++)
  {
    scanf("%d", &N);
    
    for (int i = 1; i < N; i++)
      scanf("%d", &h[i]);
    printf("Case #%d:", t);
    if (process(0, 1, N) == 0)
      printf(" Impossible\n");
    else
    {
      int lowest = 0;
      for (int i=1; i <= N; i++)
        if (y[i] < lowest)
          lowest = y[i];
      for (int i=1; i <= N; i++)
        printf(" %d", y[i] - lowest);
      printf("\n");
    }
  }
  return 0;
}
