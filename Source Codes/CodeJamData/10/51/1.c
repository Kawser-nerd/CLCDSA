#include <stdio.h>

long long vals[10];
long long primes[79498];
char erat[1000000];

long long powm(long long a, long long n, long long p)
{
  if (n == 0)
    return 1;
  long long r = powm(a, n/2, p);
  r = (r*r)%p;
  if (n&1)
    return (a*r)%p;
  else
    return r;
}

long long inv(long long a, long long p)
{
  return powm(a, p-2, p);
}

int main()
{
  int pr = 0;
  for (long long i = 2; i < 1000000; i++)
  {
    if (erat[i] != 0)
      continue;
    primes[pr++] = i;
    for (long long j=i; j < 1000000; j += i)
      erat[j] =1;
  }
  
  int t;
  scanf("%d", &t);
  for (int c=1; c<=t; c++)
  {
    printf("Case #%d: ", c);

    int d, k;
    scanf("%d %d", &d, &k);
    for (int i=0; i<k; i++)
      scanf("%d", &vals[i]);

    long long next = -1;

    if (k == 1)
      goto dontknow;
    if (k == 2)
    {
      if (vals[0] != vals[1])
        goto dontknow;
      next = vals[0];
      goto result;
    }
    if (k <= 2)
      goto dontknow;
    
    long long limitu = 1;
    for (int i=0; i<d; i++)
      limitu *= 10;
    long long limitl = 0;
    for (int i=0; i<k; i++)
      if (limitl < vals[i])
        limitl = vals[i];

    for (int pp = 0; pp < 79498; pp++)
    {
      long long p = primes[pp];
      if (p > limitu)
        break;
      if (p <= limitl)
        continue;
      
      long long d1 = (p + vals[1] - vals[0])%p;
      long long d2 = (p + vals[2] - vals[1])%p; 
      
      long long A;
      if (d1 != 0)
        A = (d2*inv(d1, p))%p;
      else
      {
        if (d2 != 0)
          goto cantbe;
        A = 0;
      }
      long long S = vals[0];
      long long B = (p + vals[1] - (A*S)%p)%p;

      for (int n = 0; n < k; n++)
      {
        if (S != vals[n])
          goto cantbe;
        S = (A*S + B)%p;
      }
      if (next == -1)
        next = S;
      else
        if (next != S)
          goto dontknow;
cantbe:
      ;
    }
result:
    printf("%d\n", next);
    continue;
dontknow:
    printf("I don't know.\n");
  }
}
