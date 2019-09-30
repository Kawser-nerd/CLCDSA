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
#define MAXN 88
int N;
vector<int> graph[MAXN];
int dist[MAXN][MAXN], C[MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];

bool edge_used(int a, int b, int s1, int s2, int p1, int p2) {
  if (dist[s1][a] + 1 + dist[b][p1] == dist[s1][p1]) return true;
  if (dist[s1][b] + 1 + dist[a][p1] == dist[s1][p1]) return true;
  if (dist[s2][a] + 1 + dist[b][p2] == dist[s2][p2]) return true;
  if (dist[s2][b] + 1 + dist[a][p2] == dist[s2][p2]) return true;
  return false;
}

bool vertex_used(int v, int s1, int s2, int p1, int p2) {
  if (dist[s1][v] + dist[v][p1] == dist[s1][p1]) return true;
  if (dist[s2][v] + dist[v][p2] == dist[s2][p2]) return true;
  return false;
}

int solve(int s1, int s2, int p1, int p2) {
  if (dp[s1][s2][p1][p2] >= 0) return dp[s1][s2][p1][p2];
  int steps1 = dist[s1][p1], steps2 = dist[s2][p2];

  bool can_move1 = false, can_move2 = false;
  REP(j, graph[p1].size()) if (!edge_used(p1, graph[p1][j], s1, s2, p1, p2)) can_move1 = true;
  REP(j, graph[p2].size()) if (!edge_used(p2, graph[p2][j], s1, s2, p1, p2)) can_move2 = true;
  if (!can_move1 && !can_move2) return dp[s1][s2][p1][p2] = 0;

  if (!can_move2 || (can_move1 && steps1 == steps2)) {
    int ans = -INF;
    REP(j, graph[p1].size()) {
      int n = graph[p1][j];
      if (edge_used(p1, n, s1, s2, p1, p2)) continue;
      int change_score = !vertex_used(n, s1, s2, p1, p2) ? C[n] : 0;
      ans = max(ans, solve(s1, s2, n, p2) + change_score);
    }
    return dp[s1][s2][p1][p2] = ans;
  }
  else {
    int ans = INF;
    REP(j, graph[p2].size()) {
      int n = graph[p2][j];
      if (edge_used(p2, n, s1, s2, p1, p2)) continue;
      int change_score = !vertex_used(n, s1, s2, p1, p2) ? C[n] : 0;
      ans = min(ans, solve(s1, s2, p1, n) - change_score);
    }
    return dp[s1][s2][p1][p2] = ans;
  }
}

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  REP(t, T) {
    scanf("%d", &N);
    REP(i, N) scanf("%d", C + i);
    REP(i, N) REP(j, N) dist[i][j] = (i == j) ? 0 : MAXN;
    REP(i, N) graph[i].clear();
    REP(i, N - 1) {
      int j;
      scanf("%d", &j); j--;
      graph[i].push_back(j);
      graph[j].push_back(i);
      dist[i][j] = dist[j][i] = 1;
    }
    REP(k, N) REP(i, N) REP(j, N) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    REP(a, N) REP(b, N) REP(c, N) REP(d, N) dp[a][b][c][d] = -1;
    int ans = -INF;
    REP(a, N) {
      int worst = INF;
      REP(b, N) {
        int score = solve(a, b, a, b) + C[a];
        if (a != b) score -= C[b];
        // printf("a: %d b: %d ans: %d\n", a, b, score);
        worst = min(worst, score);
      }
      ans = max(ans, worst);
    }
    printf("Case #%d: %d\n", t + 1, ans);
  }
  return 0;
}
