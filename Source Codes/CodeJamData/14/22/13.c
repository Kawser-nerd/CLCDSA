#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);
  for (int t=1; t<=T; t++)
  {
    unsigned long A, B, K;
    scanf("%lu %lu %lu", &A, &B, &K);
    
    unsigned long cnt = 0;
    for (unsigned long a=0; a<A; a++)
      for (unsigned long b=0; b<B; b++)
        if ((a&b) < K)
          cnt++;
    printf("Case #%d: %llu\n", t, cnt);
  }
  return 0;
}
