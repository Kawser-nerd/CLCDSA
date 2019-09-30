/* GCJ'09 Template v.1e-9
 * Per Austrin
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

int cases;

void init() {
  scanf("%d", &cases);
}

long double packs[50];
int N, C;

long double binom[50][50];

long double Binom(int n, int k) {
  //  printf("bin %d %d\n", n, k);
  if (k == 0 || k == n) return 1;
  if (k < 0 || k > n) return 0;
  long double &res = binom[n][k];
  if (res == 0)
    res = Binom(n-1,k-1) + Binom(n-1,k);
  return res;
}

long double Packs(int have) {
  if (have == C) return 0;
  long double &res = packs[have];
  //  printf("packs %d\n", have);
  if (res == 0) {
    if (have == 0) res = 1 + Packs(N);
    else {
      long double p0 = Binom(have, N) / Binom(C, N);
      for (int y = 1; have+y <= C && y <= N; ++y) {
	long double p = Binom(C-have, y)*Binom(have, N-y) / Binom(C, N);
	res += p*Packs(have+y);
      }
      res = (res+1)/(1-p0);
    }
  }
  return res;
}

void solve(int P) {
  scanf("%d%d", &C, &N);
  memset(packs, 0, sizeof(packs));
  printf("Case #%d: %.9lf\n", P, (double)Packs(0));
}

int main(void) {
  init();
  for (int i = 1; i <= cases; ++i) solve(i);
  return 0;
}
