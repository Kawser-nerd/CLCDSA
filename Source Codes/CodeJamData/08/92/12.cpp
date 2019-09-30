#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>

#define eps 1e-9

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define sz(v)((v).size())

#define task_name "b"


using namespace std;
int w, h;

#define maxn 110

int  dx[2], dy[2], was[maxn][maxn];

int dfs( int x, int y )
{
  int res = 1;
  
  was[x][y] = 1;
  for (int i = 0; i < 2; i++)
    if (x + dx[i] >= 0 && x + dx[i] < w &&
        y + dy[i] >= 0 && y + dy[i] < h &&
        !was[x + dx[i]][y + dy[i]])
       res += dfs(x + dx[i], y + dy[i]);

  return res;
}

int main( void )
{
  freopen(task_name ".in", "r", stdin);
  freopen(task_name ".out", "w", stdout);

  int tn;
  scanf("%d", &tn);

  for (int tt = 1; tt <= tn; tt++)
  {
    printf("Case #%d: ", tt);

    int sx, sy;
    cin >> w >> h;
    for (int i = 0; i < 2; i++)
      cin >> dx[i] >> dy[i];
    cin >> sx >> sy;
    memset(was, 0, sizeof(was));
    printf("%d\n", dfs(sx, sy));

  }

   
  
  return 0;
}