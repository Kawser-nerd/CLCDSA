#include <stdio.h>

const int kPowersOf10[] = {1, 10, 100, 1000, 10000, 100000, 1000000};

int main(void)
{
  int T;
  scanf("%d", &T);
  int i, j, k, l;
  for(i = 0; i < T; i++)
  {
    int A, B;
    scanf("%d %d", &A, &B);

    int count = 0;
    int numdigits;
    if(A < 10)
      numdigits = 1;
    else if(A < 100)
      numdigits = 2;
    else if(A < 1000)
      numdigits = 3;
    else if(A < 10000)
      numdigits = 4;
    else if(A < 100000)
      numdigits = 5;
    else if(A < 1000000)
      numdigits = 6;
    else
      numdigits = 7;
    for(j = A; j < B; j++)
    {
      int x = j;
      int p = kPowersOf10[numdigits - 1];
      int sofar[10], nsofar = 0;
      for(k = 1; k < numdigits; k++)
      {
        x = (x / p) + (x % p) * 10;
        if(x > j && x <= B)
        {
          for(l = 0; l < nsofar; l++)
          {
            if(x == sofar[l])
              goto next;
          }
          sofar[nsofar++] = x;
          count++;
        next:;
        }
      }
      
      if(j == 9 || j == 99 || j == 999 || j == 9999 || j == 99999 || j == 999999)
        numdigits++;
    }

    printf("Case #%d: %d\n", i+1, count);
  }
  
  return 0;
}
