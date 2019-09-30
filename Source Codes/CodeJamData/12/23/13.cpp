#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <map>

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
  char str[1000];
  fgets(str, 999, stdin);
  int test_case = 0;
  while (test--) {
    test_case++;
    printf("Case #%d: ", test_case);
    puts("");
    solve();
  }
}

int n;
ll seq[1000];
map<ll, ull> sums;

void PrintVect(ull use) {
  bool first = true;;
  REP(i, n) {
    if (!((use >> i) & 1)) { continue; }
    if (!first) { putchar(' '); }
    first = false;
    printf("%lld", seq[i]);
  }
  puts("");
}

void solve() {
  sums.clear();
  scanf("%d", &n);
  REP(i, n) { scanf("%lld", &seq[i]); }
  sort(seq, seq + n);
  n = min(n, 50);
  ll s = 0;
  ull use = 0;
  while (true) {
    int r = rand() % n;
    if ((use >> r) & 1) {
      s -= seq[r];
    } else {
      s += seq[r];
    }
    use ^= 1LL << r;
    map<ll, ull>::iterator it = sums.find(s);
    if (it != sums.end() && it->second != use) {
      ull ans = it->second;
      PrintVect(ans);
      PrintVect(use);
      return;
    }
    sums[s] = use;
  }
}
