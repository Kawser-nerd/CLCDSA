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

#define task_name "e"


using namespace std;

char a[55][55];
int was[55][55], d[55][55], px[55][55], py[55][55], qx[55 * 55], qy[55 * 55], l, r, end[55][55],
    okX[55 * 55], okY[55 * 55], okN;

int dx[] = {1, -1, 0, 0},
    dy[] = {0, 0, 1, -1};

void add( int x, int y, int td, int a, int b )
{
  was[x][y] = 1;
  d[x][y] = td;
  px[x][y] = a;
  py[x][y] = b;
  qx[r] = x;
  qy[r++] = y;
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
    int n, m;
    cin >> n >> m;
    while (getc(stdin) != '\n');
    for (int i = 0;  i < n; i++)
      gets(a[i]);

    memset(was, 0, sizeof(was));
    memset(end, 0, sizeof(end));
    okN = 1;
    okX[0] = okY[0] = 0;
    l = r = 0;
    add(0, 0, 0, -1, -1);

    int res = 0, last = 0;

    while (l < r)
    {
      int x = qx[l], y = qy[l++];
      if (!end[x][y] && a[x][y] == 'T')
      {
        res = 0;
        int sx = x, sy = y;
        while (!end[x][y])
        {
          last += d[x][y];
          end[x][y] = 1;
          int tx = px[x][y], ty = py[x][y];
          x = tx;
          y = ty;
        }
        end[x][y] = 1;
        l = r = 0;
        memset(was, 0, sizeof(was));
        okX[okN] = sx;
        okY[okN++] = sy;
        for (int i = 0; i < okN; i++)
          add(okX[i], okY[i], 0, -1, -1);
        continue;            
      }
      if (!end[x][y])
      {
        res += d[x][y];
//        fprintf(stderr, "%d %d : %d\n", x, y, d[x][y]);
      }
      for (int i = 0; i < 4; i++)
      {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !was[nx][ny] && a[nx][ny] != '.')
          add(nx, ny, d[x][y] + 1, x, y);
      }

    }
    cout << res + last << endl;
  }

   
  
  return 0;
}