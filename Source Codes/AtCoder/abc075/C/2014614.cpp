#include <iostream>
#include <set>
#include <queue>
using namespace std;
#define MAXN 50
bool fromA2B(int n, bool g[][MAXN], int a, int b)
{
  g[a][b] = g[b][a] = false;
  bool result;

  bool reached[n];
  for (int i = 0; i < n; i++)
  {
    reached[i] = false;
  }

  queue<int> next;
  next.push(a);
  while (!next.empty())
  {
    auto p = next.front();
    next.pop();
    if (!reached[p])
    {
      reached[p] = true;
      for (int i = 0; i < n; i++)
      {
        if (g[p][i] && !reached[i])
        {
          next.push(i);
          if (i == b)
          {
            g[a][b] = g[b][a] = true;
            return false;
          }
        }
      }
    }
  }

  g[a][b] = g[b][a] = true;
  return true;
}

int main()
{
  int n, m;
  cin >> n >> m;
  bool g[MAXN][MAXN];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      g[i][j] = false;
    }
  }
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    g[a - 1][b - 1] = g[b - 1][a - 1] = true;
  }
  auto ans = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (!g[i][j])
        continue;

      if (fromA2B(n, g, i, j))
      {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}