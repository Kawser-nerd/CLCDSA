#include <stdio.h>
#include <string.h>

long long max(long long a, long long b) { return a>b?a:b; }
long long min(long long a, long long b) { return a<b?a:b; }

long long tab[100][100];
int n, m;
int a[100], b[100];
long long ac[100], bc[100];

long long track(int aa, int bb)
{
  if (aa >= n || bb >= m)
    return 0;
    
  if (tab[aa][bb] == -1)
  {
    long long best = max(track(aa+1, bb), track(aa, bb+1));
    if (a[aa] == b[bb])
    {
      int col = a[aa];
      long long ca = 0;
      for (int aaa = aa; aaa < n; aaa++)
      {
        if (a[aaa] == col)
          ca += ac[aaa];
        long long cb = 0;
        for (int bbb = bb; bbb < m; bbb++)
        {
          if (b[bbb] == col)
            cb += bc[bbb];
          best = max(best, track(aaa+1, bbb+1) + min(ca, cb));
        }
      }
    }
    tab[aa][bb] = best;
  }
  return tab[aa][bb];
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int t=1; t<=T; t++)
  {
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++)
      scanf("%lld %d", &ac[i], &a[i]);
    for (int i=0; i<m; i++)
      scanf("%lld %d", &bc[i], &b[i]);
    int k;
    k = 0;
    for (int i=1; i<n; i++)
      if (a[i] == a[k])
        ac[k] += ac[i];
      else
      {
        k++;
        a[k] = a[i];
        ac[k] = ac[i];
      }
    n = k + 1;

    k = 0;
    for (int i=1; i<m; i++)
      if (b[i] == b[k])
        bc[k] += bc[i];
      else
      {
        k++;
        b[k] = b[i];
        bc[k] = bc[i];
      }
    m = k + 1;
    memset(tab, -1, sizeof(tab));

    printf("Case #%d: %lld\n", t, track(0, 0));
  }
  return 0;
}
