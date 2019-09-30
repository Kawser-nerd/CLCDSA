#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;
 
#define all(c) ((c).begin()), ((c).end()) 
#define iter(c) __typeof((c).begin())
#define present(c, e) ((c).find((e)) != (c).end()) 
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
 
typedef long long ll;

const ll MOD = 10007;

bool rock[110][110];
ll dp[110][110];

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 1; t <= T; t++) {
    memset(rock, 0, sizeof(rock));
    memset(dp, 0, sizeof(dp));

    int W, H, R;
    scanf("%d%d%d", &W, &H, &R);
    
    rep (i, R) {
      int x, y;
      scanf("%d%d", &x, &y);
      rock[x][y] = true;
    }

    dp[1][1] = 1;
    for (int x = 1; x <= W; x++) {
      for (int y = 1; y <= H; y++) {
        if (rock[x][y]) dp[x][y] = 0;
        else {
          dp[x][y] %= MOD;

          dp[x + 2][y + 1] += dp[x][y];
          dp[x + 1][y + 2] += dp[x][y];
        }
      }
    }

    printf("Case #%d: %d\n", t, dp[W][H]);
  }
  return 0;
}
