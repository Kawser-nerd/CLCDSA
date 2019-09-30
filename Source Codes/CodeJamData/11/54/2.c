#include <stdio.h>

char num[251];

int check(long long v)
{
  long long min = 0, max = 1LL << 31;
  while(min <= max)
  {
    long long cur = (min + max)/2;
    if (cur * cur < v)
      min = cur+1;
    if (cur * cur > v)
      max = cur-1;
    if (cur * cur == v)
      return 1;
  }
  return 0;
}

int bag(int p, long long v)
{
  switch(num[p])
  {
    case 0:
      return check(v);
      break;
    case '0':
      if (bag(p+1, 2*v))
        return 1;
      break;
    case '1':
      if (bag(p+1, 2*v+1))
        return 1;
      break;
    case '?':
      num[p] = '0';
      if (bag(p+1, 2*v))
        return 1;      num[p] = '1';
      if (bag(p+1, 2*v+1))
        return 1;
      num[p] = '?';
      break;
  }
  return 0;
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int t=1; t<=T; t++)
  {
    scanf("%s", &num);
    bag(0, 0);
    printf("Case #%d: %s\n", t, num);
  }
  return 0;
}
