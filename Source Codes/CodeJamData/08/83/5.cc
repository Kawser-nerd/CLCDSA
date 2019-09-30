/* GCJ'08
 * Author: Per Austrin
 */
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;
#define dprintf debug && printf
bool debug = false;

typedef vector<int> vi;
typedef long long ll;

const ll MOD = 1000000009;

ll choose(int n, int k) {
  ll res = 1;
  if (k > n) return 0;
  for (int i = 1; i <= k; ++i) {
    (res *= (n-i+1)) %= MOD;
  }
  return res;
}

void init() {
}

vi adj[1000];

int n;
ll k;
ll cols[1000];

ll Cols(int v, int par) {
  ll &res = cols[v];
  if (res == -1) {
    res = k;
    if (par != -1) res = choose(k-adj[par].size(), adj[v].size()-1);
    for (vi::iterator it = adj[v].begin(); it != adj[v].end(); ++it)
      if (*it != par)
	(res *= Cols(*it, v)) %= MOD;
    if (adj[v].size() == 1 && par != -1) res = 1;
  }
  return res;
}


void solve(int P) {
  scanf("%d%lld", &n, &k);
  for (int i = 0; i <= 1000; ++i) adj[i].clear();
  for (int i = 0; i < n-1; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    assert(1 <= a && a <= n);
    assert(1 <= b && b <= n);
    assert(a != b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  memset(cols, -1, sizeof(cols));
  ll res = -1;
  for (int i = 1; i <= n; ++i) {
    if (adj[i].size() == 1) { res = Cols(i, -1); break; }
  }
  assert(res != -1);
  printf("Case #%d: %lld\n", P, res);
}

int main() {
  int n;
  scanf("%d", &n);
  init();
  for (int i = 1; i <= n; ++i) solve(i);
  return 0;
}
