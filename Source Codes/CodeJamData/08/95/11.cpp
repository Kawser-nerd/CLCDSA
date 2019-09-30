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

#define task_name "d"


using namespace std;

int dp[2][1 << 16], can[2][1 << 16];
char f[20][20];

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

    for (int i = 0; i < n; i++)
      gets(f[i]);

    memset(can, 0, sizeof(can));
    can[0][0] = 1;
    dp[0][0] = 0;
    int curr = 0;
    int res = -1000000;
    for (int x = 0; x < m; x++)
    {
      for (int y = 0; y < n; y++)
      {
        for (int code = 0; code < (1 << n); code++)
        {
          if (can[curr][code])
          {
            if (f[y][x] == '#' || f[y][x] == '?')
            {
              int cost = 4;
              if (y && ((code >> (y - 1)) & 1))
                cost -= 2;
              if (((code) >> (y)) & 1)
                cost -= 2;
              int nc = code | (1 << y);
              if (!can[1 - curr][nc] || dp[1 - curr][nc] < dp[curr][code] + cost)
                dp[1 - curr][nc] = dp[curr][code] + cost,
                can[1 - curr][nc] = 1;  
            }
            if (f[y][x] == '?' || f[y][x] == '.')
            {
              int nc = code & ~(1 << y);
              if (!can[1 - curr][nc] || dp[1 - curr][nc] < dp[curr][code])
                dp[1 - curr][nc] = dp[curr][code],
                can[1 - curr][nc] = 1;  
            }
          }
        }
        memset(can[curr], 0, sizeof(can[curr]));
        curr = 1 - curr;
        
      }
    }

    for (int code = 0; code < (1 << n); code++)
     if (can[curr][code])
       res >?= dp[curr][code];
    cout << res << endl;
  }                   

   
  
  return 0;
}