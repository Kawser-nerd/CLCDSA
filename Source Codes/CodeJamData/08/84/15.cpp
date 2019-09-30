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

#define mod 30031

int dp[10000][1 << 10];

int main( void )
{
  freopen(task_name ".in", "r", stdin);
  freopen(task_name ".out", "w", stdout);

  int tn;
  scanf("%d", &tn);

  for (int tt = 1; tt <= tn; tt++)
  {
    printf("Case #%d: ", tt);
    int n, k, p;
    scanf("%d%d%d", &n, &k, &p);
    memset(dp, 0, sizeof(dp));
    dp[0][(1 << k) - 1] = 1;
    for (int i = 0; i < n - k; i++)
      for (int c = 0; c < (1 << p); c++)
        if (c & 1)
        if (dp[i][c])
        {
//          fprintf(stderr, "%d %d :\n", i, c);
          int ne = c >> 1;
          for (int j = 0; j < p; j++)
            if (!(ne & (1 << j)) && j + i + 1 < n)
            {
  //            fprintf(stderr, "%d-> %d\n", c, (ne | (1 <<  j)));
              dp[i + 1][ne | (1 << j)] = (dp[i + 1][ne | (1 << j)] + dp[i][c]) % mod;
            }
        }
    printf("%d\n", dp[n - k][(1 << k) - 1]);
    
  }

   
  
  return 0;
}