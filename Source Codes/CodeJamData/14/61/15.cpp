/* Writen by Filip Hlasek 2014 */
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

#define MAXN 2222
#define INF 111111111
int N;
char board[MAXN][MAXN];

bool row[MAXN], col[MAXN];

int solve(int b) {
  set<string> s0, s1;
  REP(i, 2 * N) {
    string s = "";
    REP(j, 2 * N) s.push_back(board[i][j]);
    s0.insert(s);
    s = "";
    REP(j, 2 * N) s.push_back(board[j][i]);
    s1.insert(s);
  }
  if (s0.size() > 2 || s1.size() > 2) return INF;
  REP(i, 2 * N) {
    int cnt = 0;
    REP(j, 2 * N) cnt += (board[i][j] == '0');
    if (cnt != N) return INF;
    cnt = 0;
    REP(j, 2 * N) cnt += (board[j][i] == '0');
    if (cnt != N) return INF;
  }

  int ans = 0, cr = 0, cc = 0;
  REP(i, 2 * N) cr += (board[0][i] - '0' != i % 2);
  REP(i, 2 * N) cc += (board[i][0] - '0' != i % 2);
  cr = min(2 * N - cr, cr);
  cc = min(2 * N - cc, cc);
  return (cr + cc) / 2;
}

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  FOR(testcase, 1, T) {
    scanf("%d", &N);
    REP(i, 2 * N) scanf("%s", board[i]);

    printf("Case #%d: ", testcase);

    int ans = min(solve(0), solve(1));
    if (ans == INF) printf("IMPOSSIBLE\n");
    else printf("%d\n", ans);
  }
 return 0;
}
