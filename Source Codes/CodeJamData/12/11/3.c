#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int T, t, i;
  scanf("%d", &T);
  for(t = 1; t <= T; t++)
  {
    int A, B;
    scanf("%d %d", &A, &B);
    double *P = malloc(A * sizeof(double));
    double *Q = malloc((A+1) * sizeof(double));

    for(i = 0; i < A; i++)
      scanf("%lf", &P[i]);
    double prod = 1.0;
    for(i = 0; i < A; i++)
    {
      Q[i] = prod;
      prod *= P[i];
    }
    Q[A] = prod;

    double best = B + 2;
    //printf("  start: %f\n", best);

    for(i = 0; i < A; i++)
    {
      double e = (2 * i + B - A + 1) + (1 - Q[A - i]) * (B + 1);
      //printf("  %d: %f\n", i, e);
      if(e < best)
        best = e;
    }

    printf("Case #%d: %.9f\n", t, best);
    free(P);
    free(Q);
  }
  return 0;
}
