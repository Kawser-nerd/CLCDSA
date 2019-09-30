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

#define task_name "c"


using namespace std;

int f[10][10], t[6][6], x[10][10],
    dx[] = {0, 1, 1, 1, 0, -1, -1, -1, 0},
    dy[] = {1, 1, 0, -1, -1, -1, 0, 1, 0};

int main( void )
{
  freopen(task_name ".in", "r", stdin);
  freopen(task_name ".out", "w", stdout);

  int tn;
  scanf("%d", &tn);

  for (int tt = 1; tt <= tn; tt++)
  {
    fprintf(stderr, "%d\n", tt);
    printf("Case #%d: ", tt);
    int r, c;
    cin >> r >> c;

    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++)
        cin >> f[i + 1][j + 1];
    int mx = 1 << (r * c);
    int res = 0;
    for (int i = 0; i < mx; i++)
    {
      memset(t, 0, sizeof(t));
      for (int a = 0; a < r; a++)
        for (int b = 0; b < c; b++)
          if ((i >> (a * c + b)) & 1)
            t[a + 1][b + 1] = 1;


      for (int a = 0; a < r; a++)
        for (int b = 0; b < c; b++)
        {
          x[a + 1][b + 1] = 0;
          for (int d = 0; d < 9; d++)
            x[a + 1][b + 1] += t[a + dx[d] + 1][b + dy[d] + 1];
        }
      bool ok = true;
      for (int a = 0; a < r; a++)
       for (int b = 0; b < c; b++)
         ok &= f[a + 1][b + 1] == x[a + 1][b + 1];
      if (ok)
      {
        int y = 0;
        for (int b = 0; b < c; b++)
          y += t[r / 2 + 1][b + 1];
        res >?= y;
          
      }
    }          
    printf("%d\n", res);
  }

   
  
  return 0;
}