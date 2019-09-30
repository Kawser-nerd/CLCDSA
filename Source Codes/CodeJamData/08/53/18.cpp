#include <cstdio>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

#define m 110
#define mm (m * m)

int w, h, nt, u[mm], ma[mm], ok[mm];
char a[m][m];
vector <int> c[mm];

int dfs( int v )
{
  u[v] = 1;
  forn (i, c[v].size())
    if (ma[c[v][i]] == -1 || (!u[ma[c[v][i]]] && dfs(ma[c[v][i]])))
    {
      ma[c[v][i]] = v;
      return 1;
    }
  return 0;
}

void adde( int a, int b )
{
  c[a].push_back(b);
  c[b].push_back(a);
}

int main()
{
  freopen("seat.in", "r", stdin);
  freopen("seat.out", "w", stdout);
  scanf("%d", &nt);
  forn (tt, nt)
  {
    printf("Case #%d: ", tt + 1);
    scanf("%d%d", &h, &w);
    forn (i, h)
      scanf("%s", a[i]);
    forn (i, h)
      forn (j, w)
      {
        int v = i * w + j;
        ok[v] = (a[i][j] == '.');
      }
    forn (i, w * h)
      c[i].clear();
    forn (i, h)
      forn (j, w)
      {
        if (!ok[i * w + j])
          continue;
        if (i > 0)
        {
          if (j > 0 && a[i - 1][j - 1] == '.')
            adde(i * w + j, (i - 1) * w + j - 1);
          if (j < w - 1 && a[i - 1][j + 1] == '.')
            adde(i * w + j, (i - 1) * w + j + 1);
        }
        if (j > 0 && a[i][j - 1] == '.')
          adde(i * w + j, i * w + j - 1);
        if (j < w - 1 && a[i][j + 1] == '.')
          adde(i * w + j, i * w + j + 1);
      }
    int ans = 0;
    memset(ma, -1, sizeof(ma));
    forn (i, w * h)
      if (ok[i] && (i % w) % 2 == 0)
      {
        memset(u, 0, sizeof(u));
        ans++, ans -= dfs(i);
      }
      else if (ok[i] && (i % w) % 2 == 1)
        ans++;
    printf("%d\n", ans);    
  }
  return 0;
}
