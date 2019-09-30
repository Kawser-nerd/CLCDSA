#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

uint ts[128];

uint gcd(uint a, uint b)
{
  if (a<b)
  {
    const uint t = a;
    a = b;
    b = t;
  }
  while (b != 0)
  {
    const uint t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int uintcmp(const void *a, const void *b)
{
  return *(const uint *)a > *(const uint *)b;
}

int main()
{
  uint n_cases;
  scanf("%u", &n_cases);
  for (uint current_case=0; current_case<n_cases; current_case++)
  {
    uint c;
    scanf("%u", &c);
    for (uint i=0; i<c; i++)
      scanf("%u", &ts[i]);

    qsort(ts, c, sizeof(uint), uintcmp);

    uint maxt = ts[1]-ts[0];
    for (uint i=2; i<c; i++)
      maxt = gcd(maxt, ts[i]-ts[i-1]);

    uint y = 0;
    if (ts[c-1]%maxt != 0)
      y = maxt-(ts[c-1]%maxt);

    printf("Case #%u: %u\n", current_case+1, y);
  }
}

