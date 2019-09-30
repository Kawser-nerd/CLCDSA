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
typedef long long ll;

void init() {
}

void solve(int P) {
  int lim, K, L;
  scanf("%d%d%d", &lim, &K, &L);

  assert(lim <= 1000);

  int freq[10000];
  
  for (int i = 0; i < L; ++i) scanf("%d", freq+i), assert(freq[i] <= 1000000);

  sort(freq, freq + L);
  
  ll ans = 0;
  int used = 0, x = 1;
  for (int i = L-1; i >= 0; --i) {
    ans += x*freq[i];
    if (++used == K) ++x, used = 0;
  }
  
  printf("Case #%d: %lld\n", P, ans);
}

int main() {
  int n;
  scanf("%d", &n);
  init();
  for (int i = 1; i <= n; ++i) solve(i);
  return 0;
}
