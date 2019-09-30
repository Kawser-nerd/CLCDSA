#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef long long LL;

#define FOR(i,n) for (i = 0; i < (n); i++)
#define FORI(i,a,b) for (i = (a); i <= (b); i++)
#define FORD(i,a,b) for (i = (a); i >= (b); i--)
#define FOREACH(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define ZERO(a) memset(a, 0, sizeof(a))
#define MINUS(a) memset(a, -1, sizeof(a))
#define SZ(a) (a.size())
#define MP(a, b) make_pair(a, b)
#define SHL(a,b) ((a) << (b))
#define SHR(a,b) ((a) >> (b))
#define FI first
#define SE second
#define PB push_back

char x[1<<20];
int mark[1<<20];
int next[1<<20];

int isCons(char c)
{
  return c !=  'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}

int okSlow(char *y, int z, int n)
{
  int i, j;
  j = 0;
  FOR(i, z)
  {
    if (isCons(*(y + i)))
    {
      j++;
    }
    else j = 0;
    if (j >= n) return 1;
  }
  return 0;
}

int main()
{
  int tc, t;
  int n, i, j, k, l;
  LL res;
  scanf("%d", &tc);
  FOR(t, tc)
  {
    ZERO(mark);
    scanf("%s %d", x, &n);
    l = strlen(x);
    j = 0;
    FOR(i, l)
    {
      next[i] = l;
      if (isCons(x[i])) j++; else j = 0;
      if (j == n)
      {
        j--;
        mark[i - j] = 1;
        next[i - j] = i - j;
        FORD(k, i - j - 1, 0)
          if (mark[k]) break; else next[k] = i - j;
      }
    }

    res = 0;
    FOR(i, l)
    {
      if (next[i] != l)
        res += l - (next[i] + n - 1);
    }

    printf("Case #%d: %lld\n", t + 1, res);
  }
  return 0;
}

