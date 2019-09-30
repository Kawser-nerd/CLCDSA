#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

void solve();
int main() {
  int test;
  scanf("%d", &test);
  int test_case = 0;
  while (test--) {
    test_case++;
    printf("Case #%d: ", test_case);
    solve();
  }
}

void solve() {
  ll n, pd, pg;
  ll m = 1;
  scanf("%lld %lld %lld", &n, &pd, &pg);
  if (pg == 0) {
    if (pd == 0) {
      goto ok;
    } else {
      goto ng;
    }
  } else if (pg == 100) {
    if (pd == 100) {
      goto ok;
    } else {
      goto ng;
    }
  }
  if (pd % 5 == 0) { pd /= 5; m *= 5; }
  if (pd % 5 == 0) { pd /= 5; m *= 5; }
  if (pd % 2 == 0) { pd /= 2; m *= 2; }
  if (pd % 2 == 0) { pd /= 2; m *= 2; }
  if (n >= 100 / m) { goto ok; }
  else { goto ng; }
ok:;
   puts("Possible");
   return;
ng:;
   puts("Broken");
   return;
}
