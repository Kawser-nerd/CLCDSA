/* Written by Filip Hlasek 2014 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define INF 1000000000
#define MAXN 222
#define MAX 2500
int dp[MAXN][2 * MAX];
int P, Q, N, H[MAXN], G[MAXN];

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  REP(t, T) {
    scanf("%d%d%d", &P, &Q, &N);
    REP(i, N) scanf("%d%d", H + i, G + i);

    REP(i, N + 1) REP(j, 2 * MAX) dp[i][j] = -INF;
    dp[0][MAX] = 0;
    int ans = 0;
    REP(i, N) REP(dd, 2 * MAX) if (dp[i][dd] > -INF) {
      int tower_hits = (H[i] + Q - 1) / Q;
      dp[i + 1][dd - tower_hits] = max(dp[i + 1][dd - tower_hits], dp[i][dd]);
      int rem = H[i] - (tower_hits - 1) * Q;
      int my_hits = (rem + P - 1) / P;
      int nd = dd - (tower_hits - 1) + my_hits;
      if (nd <= MAX + 1) dp[i + 1][nd] = max(dp[i + 1][nd], dp[i][dd] + G[i]);
    }
    REP(dd, 2 * MAX + 2) ans = max(ans, dp[N][dd]);
    printf("Case #%d: %d\n", t + 1, ans);
  }
  return 0;
}
