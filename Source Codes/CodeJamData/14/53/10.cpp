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

int N;

#define MAXN 18
map<int, int> m;
bool enter[MAXN];
int id[MAXN];

bool dp[MAXN][1 << MAXN];

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  REP(t, T) {
    printf("Case #%d: ", t + 1);
    m.clear();
    scanf("%d", &N);
    REP(i, N) {
      char tmp[5];
      scanf("%s%d", tmp, id + i);
      enter[i] = tmp[0] == 'E';
      if (id[i] && m.find(id[i]) == m.end()) m[id[i]] = m.size();
    }
    REP(i, N + 1) REP(j, 1 << N) dp[i][j] = (i == 0);
    REP(i, N) REP(mask, 1 << N) if (dp[i][mask]) {
      if (id[i]) {
        int j = m[id[i]];
        bool inside = (mask & (1 << j)) != 0;
        if ((enter[i] && !inside) || (!enter[i] && inside)) {
          dp[i + 1][mask ^ (1 << j)] = true;
        }
      }
      else {
        REP(j, N) {
          bool inside = (mask & (1 << j)) != 0;
          if ((enter[i] && !inside) || (!enter[i] && inside)) {
            dp[i + 1][mask ^ (1 << j)] = true;
          }
        }
      }

    }
    int ans = N + 1;
    REP(mask, 1 << N) if (dp[N][mask]) {
      int cnt = 0;
      REP(i, N) if (mask & (1 << i)) cnt++;
      ans = min(ans, cnt);
    }
    if (ans == N + 1) printf("CRIME TIME\n");
    else printf("%d\n", ans);
  }
  return 0;
}
