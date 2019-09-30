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

typedef long long ll;

ll hw[1<<12];

void init() {
  hw[0] = 0;
  for (int i = 1; i < 1<<12; ++i)
    hw[i] = (i&1) + hw[i/2];
}

const ll MOD = 30031;

ll ways[2][1<<12];
ll extract[100000];
int n, k, p;

void solve(int P) {

  scanf("%d%d%d", &n, &k, &p);

  if (p > n) p = n;

  int q = p+1;
  int end = 0, start = 0;
  for (int i = 0; i < k; ++i)
    end |= (1<<i);
  for (int i = q-k; i < q; ++i)
    start |= (1<<i);

  memset(ways, 0, sizeof(ways));
  ways[0][end] = 1;
  for (int i = end+1; i < (1<<q); ++i) {
    ways[0][i] = 0;
    if (hw[i] == k) {
      for (int a = p; a >= 0; --a)
	if (i & (1<<a)) {
	  int blim = 0;
	  if (!(i & (1<<(a-1)))) blim = a-1;
	  for (int b = a-1; b >= blim; --b)
	    if (!(i & (1<<b)))
	      (ways[0][i] += ways[0][i ^ (1<<a) ^ (1<<b)]) %= MOD;
	  break;
	}
    }
  }
  extract[0] = ways[0][start];
  dprintf("%lld\n", ways[0][10]);
  dprintf("initways %lld, start %d\n", extract[0], start);
  for (int t = 1; t <= n-q; ++t) {
    memset(ways[t&1], 0, sizeof(ways[t&1]));
    for (int i = 0; i < (1<<q); ++i) {
      if (hw[i] == k && (i & (1<<p))) {
	int alim = 0;
	if (!(i & (1<<(p-1)))) alim = p-1;
	for (int a = p-1; a >= alim; --a) {
	  if (!(i & (1<<a))) {
	    int X = ((i|(1<<a))<<1)&((1<<q)-1);
	    //	    printf("ways %d %d += ways %d %d (%lld)\n",		   		   t, i, t-1, X, ways[(t&1)^1][X]);
	    (ways[t&1][i] += ways[(t&1)^1][X]) %= MOD;
	  }
	}
      }
    }
  }
  
  printf("Case #%d: %lld\n", P, ways[(n-q)&1][start]);
}

int main() {
  int n;
  scanf("%d", &n);
  init();
  for (int i = 1; i <= n; ++i) solve(i);
  return 0;
}
