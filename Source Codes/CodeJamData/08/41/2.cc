/* GCJ'08
 * Author: Per Austrin
 */
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <algorithm>
//#include <string>
//#include <map>
//#include <vector>

using namespace std;
#define dprintf debug && printf
bool debug = false;

void init() {
}

const int inf = 1<<29;

int M, V;
int nt[20000], val[20000];
int change[20000];
int best[20000];

int Best(int x) {
  if (val[x] == V) return 0;
  if (2*x > M) return inf;
  int &res = best[x];
  if (res == -1) {
    res = inf;
    for (int t = 0; t < 2; ++t) {
      if (t != nt[x] && !change[x]) continue;
      int cost = t != nt[x];
      if (t^V == 1) cost += min(Best(2*x), Best(2*x+1));
      else cost += Best(2*x) + Best(2*x+1);
      res <?= cost;
    }
    //    printf("best %d = %d\n", x, res);
  }
  return res;
}

void solve(int P) {
  scanf("%d%d", &M, &V);

  for (int i = 1; i <= (M-1)/2; ++i) {
    scanf("%d%d", nt+i, change+i);
  }
  for (int i = (M+1)/2; i <= M; ++i) {
    scanf("%d", val+i);
  }
  for (int i = (M-1)/2; i >= 1; --i) {
    val[i] = nt[i] ? (val[2*i] && val[2*i+1]) : (val[2*i] || val[2*i+1]);
    //    printf("val %d = %d (nt %d, children %d %d)\n", i, val[i], nt[i], val[2*i], val[2*i+1]);
  }
  
  memset(best, -1, sizeof(best));
  int x = Best(1);
  if (x < inf)
    printf("Case #%d: %d\n", P, x);
  else 
    printf("Case #%d: IMPOSSIBLE\n", P);
}

int main() {
  int n;
  scanf("%d", &n);
  init();
  for (int i = 1; i <= n; ++i) solve(i);
  return 0;
}
