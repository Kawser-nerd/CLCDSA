#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;

bool debug = false;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef map<string, int> msi;
typedef set<string> ss;
typedef set<pii> spii;

const double pi = 2.0*acos(0.0);

int CASES;

void init() {
  assert(scanf("%d", &CASES) == 1);
}

int print(const char *err, ...) {
  va_list pvar;
  va_start(pvar, err);
  vfprintf(stderr, err, pvar);
  return vfprintf(stdout, err, pvar);
}

int dprint(const char *err, ...) { 
  if (debug) {
    va_list pvar;
    va_start(pvar, err);
    return vfprintf(stderr, err, pvar);
  }
  return 0;
}

int N;
vi adj[500];
int dst[500];

int maxthreat[500][500];

int Delta(int w, int u, int v) {
  vi::iterator wi = adj[w].begin(), ui = adj[u].begin(), vi = adj[v].begin();
  int x = 0;
  for ( ; wi != adj[w].end(); ++wi) {
    while (ui != adj[u].end() && *ui < *wi) ++ui;
    if (ui != adj[u].end() && *ui == *wi) continue;
    while (vi != adj[v].end() && *vi < *wi) ++vi;
    if (vi != adj[v].end() && *vi == *wi) continue;
    ++x;
  }
  return x;
}

int MaxThreat(int u, int v) {
  int &ans = maxthreat[u][v];
  if (dst[v] == 1) return 0;
  if (ans == -1) {
    ans = 0;
    for (vi::iterator it = adj[v].begin(); it != adj[v].end(); ++it)
      if (dst[*it] < dst[v]) {
	int x = Delta(*it, u, v);
	ans = max(ans, x + MaxThreat(v, *it));
      }
  }
  return ans;
}

void solve(int P) {
  int W;
  assert(scanf("%d%d", &N, &W) == 2);
  for (int i = 0; i <= N; ++i) adj[i].clear();
  for (int i = 0; i < W; ++i) {
    int x, y;
    assert(scanf("%d,%d", &x, &y) == 2);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 0; i < N; ++i)
    sort(adj[i].begin(), adj[i].end());
  memset(dst, 0x1f, sizeof(dst));
  dst[1] = 0;
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int x = q.front(); q.pop();
    int dd = dst[x]+1;
    for (vi::iterator it = adj[x].begin(); it != adj[x].end(); ++it)
      if (dst[*it] > dd) {
	dst[*it] = dd;
	q.push(*it);
      }
  }
  memset(maxthreat, -1, sizeof(maxthreat));
  int t = adj[0].size() + MaxThreat(N, 0);
  if (dst[0] > 1) t -= dst[0];
  print("Case #%d: %d %d\n", P, dst[0]-1, t);
}

int main(void) {
  init();
  for (int i = 1; i <= CASES; ++i) solve(i);
  return 0;
}
