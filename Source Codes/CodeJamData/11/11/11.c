#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);
  for (int t=1; t<=T; t++)
  {
    int good = 0;
    unsigned long long n, pd, pg;
    scanf("%lld %lld %lld", &n, &pd, &pg);
    if (pg == 100 || pg == 0)
      good = (pd == pg);
    else if (n >= 100)
      good = 1;
    else
      for (int d = 1; d <= n; d++)
        if ((d*pd)%100 == 0)
          good = 1;
    printf("Case #%d: %s\n", t, good?"Possible":"Broken");
  }
  return 0;
}
