#include <stdio.h>

int main()
{
  int T;

  scanf("%d ", &T);

  int Q;

  for (Q = 1; Q <= T; Q++)
  {
    long B;
    long N;
    long M[1001];

    scanf("%ld ", &B);
    scanf("%ld ", &N);

    long k;

    for (k = 0; k < B; k++)
    {
      scanf("%ld ", M + k);
    }

    if (N <= B)
    {
      printf("Case #%d: %ld\n", Q, N);
      continue;
    }

    long left = 0;
    long right = 1e17L;
    long peopleServedLeft = B;

    while (right > left + 1)
    {
      long c = (left + right) / 2;

      long peopleServed = B;

      for (k = 0; k < B; k++)
      {
        peopleServed += c / M[k];
      }

      if (peopleServed < N)
      {
        left = c;
        peopleServedLeft = peopleServed;
      }
      else
      {
        right = c;
      }
    }

//    printf("-- waiting for %ld mins\n", left);

    // left has less than N people served, right has at least N people served
    // find the lowest mod

    long lowestMod = 100001;

    for (k = 0; k < B; k++)
    {
      long mod = M[k] - (left % M[k]);

      if (mod == 1)
      {
        peopleServedLeft++;

        if (peopleServedLeft == N)
        {
          break;
        }
      }
    }

    printf("Case #%d: %ld\n", Q, k + 1);
  }
}