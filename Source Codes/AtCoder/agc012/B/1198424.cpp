#include <iostream>
#include <vector>
#define REP(i, a, n) for(int i = (a); i <= (n); i++)
using namespace std;

int N, M, Q, v[100001], d[100001], c[100001];
vector<int> E[100001];
int dp[11][100001];

void dfs(int v, int d, int c) {
  if(dp[d][v] == -1) dp[d][v] = c;
  if(d == 0) return;
  if(dp[d - 1][v] == -1) dfs(v, d - 1, c);
  for(int i = 0; i < E[v].size(); i++) if(dp[d - 1][E[v][i]] == -1) dfs(E[v][i], d - 1, c);
}

int main(void) {
  cin >> N >> M;
  REP(i, 1, M) {
    int a, b; cin >> a >> b;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  cin >> Q;
  REP(i, 1, Q) cin >> v[i] >> d[i] >> c[i];

  REP(i, 0, 10) REP(j, 1, N) dp[i][j] = -1;
  for(int i = Q; i > 0; i--) dfs(v[i], d[i], c[i]);

  REP(i, 1, N) cout << (dp[0][i] == -1 ? 0 : dp[0][i]) << endl;

  return 0;
}