#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned char byte;
typedef pair<int, int> pii;
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define mp make_pair

int readint() {
  int i;
  scanf("%d", &i);
  return i;
}

int k;
int dp[50010][510];

vector<int> g[50010];
bool used[50010];

vector<int> child[50010];

ll result = 0;

void dfs(int v) {
  if (used[v]) return;
  used[v] = true;

  dp[v][0] = 1;
  forn (i, g[v].size()) {
    int to = g[v][i];
    if (used[to]) continue;
    child[v].push_back(to);
    dfs(to);
    forn (j, k) dp[v][j + 1] += dp[to][j];
  }

  result += dp[v][k];
  //cerr << v << ": " << dp[v][k] << endl;
  forn (i, child[v].size()) {
    int to = child[v][i];
    for (int j = 0; 2 * (j + 1) < k; ++j) {
      int need = k - (j + 1);
      int sumoth = dp[v][need] - dp[to][need - 1];
      result += ll(sumoth) * dp[to][j];
    }
  }

  ll tmp = 0;
  if (k % 2 == 0) {
    int need = k / 2;
    forn (i, child[v].size()) {
      int to = child[v][i];
      int sumoth = dp[v][need] - dp[to][need - 1];
      tmp += ll(sumoth) * dp[to][need - 1];
    }
  }
  if (tmp % 2 == 1) exit(-1);
  result += tmp / 2;
}

int main() {
  int n = readint();
  k = readint();
  forn (i, n - 1) {
    int a = readint() - 1, b = readint() - 1;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0);

  cout << result << endl;
  
  return 0;
}