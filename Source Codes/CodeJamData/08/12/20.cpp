#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef vector <int> vi;

#define pb push_back

#define maxn 2010
#define maxm 2010

int n, m;
int t[maxm], ans[maxn];
vi x[maxm], y[maxm];

int main()
{
  int tn;
  scanf("%d", &tn);
  for (int test = 1; test <= tn; test++)
  {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
      scanf("%d", &t[i]);
      for (int j = 0; j < t[i]; j++)
      {
        int a, b;
        scanf("%d%d", &a, &b);
        x[i].pb(a - 1), y[i].pb(b);
      }
    }
    memset(ans, 0, sizeof(ans));
    bool ok = true;
    while (ok)
    {
      bool change = false;
      for (int i = 0; i < m; i++)
      {
        bool good = false;
        int tt = -1;
        for (int j = 0; j < t[i] && !good; j++)
          if (ans[x[i][j]] == y[i][j])
            good = true;
          else if (y[i][j] == 1)
            tt = x[i][j];
        if (good)
          continue;
        if (tt == -1)
        {
          ok = false;
          break;
        }
        ans[tt] = 1;
        change = true;
      }
      if (!change)
        break;
    }
/*    int res = 0;
    for (int i = 0; i < n; i++)
      res += ans[i];
    {
      for (int pr = 0; pr < (1 << n); pr++)
      {
        bool bad = false;
        for (int i = 0; i < n; i++)
          ans[i] = (pr >> i) & 1;
        for (int i = 0; i < m; i++)
        {
          bool good = false;
          for (int j = 0; j < t[i] && !good; j++)
            if (ans[x[i][j]] == y[i][j])
              good = true;
          if (!good)
            bad = true;
        }
        if (bad)
          continue;
        int tmp = 0;
        for (int i = 0; i < n; i++)
          tmp += ans[i];
        if ((!ok && !bad) || res > tmp)
          fprintf(stderr, "baga!\n");
      }
    }*/
    printf("Case #%d:", test);
    if (ok)
      for (int i = 0; i < n; i++)
        printf(" %d", ans[i]);
    else
      printf(" IMPOSSIBLE");
    puts("");
    for (int i = 0; i < m; i++)
      x[i].clear(), y[i].clear();
  }
  return 0;
}
