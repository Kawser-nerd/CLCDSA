#include <stdio.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int main(void)
{
  int T;
  scanf("%d", &T);

  int i, j;
  for(i = 0; i < T; i++)
  {
    int N, S, P;
    scanf("%d %d %d", &N, &S, &P);
    int points[1000];
    for(j = 0; j < N; j++)
      scanf("%d", &points[j]);

    int definitely = 0, maybe = 0;
    for(j = 0; j < N; j++)
    {
      if(points[j] >= 3*P - 2)
        definitely++;
      else if(points[j] >= 3*P - 4 && points[j] >= 2 && points[j] <= 28)
        maybe++;
    }

    int answer = definitely + MIN(maybe, S);
    printf("Case #%d: %d\n", i+1, answer);
  }
  
  return 0;
}
