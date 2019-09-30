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
  char str[1000];
  fgets(str, 999, stdin);
  int test_case = 0;
  while (test--) {
    test_case++;
    printf("Case #%d:", test_case);
    solve();
  }
}

int n;
int seq[1000];
double ans[1000];
void solve() {
  scanf("%d", &n);
  double X = 0.0;
  REP(i, n) { scanf("%d", &seq[i]); X += seq[i]; }
  REP(i, n) {
    double left = 0.0;
    double right = 1.0;
    REP(iter, 200) {
      double mid = (left + right) / 2.0;
      double p = seq[i] + mid * X;
      double sum = mid;
      REP(j, n) {
        if (i == j) { continue; }
        double q = (p - seq[j]) / X;
        if (q < 0) { q = 0.0; }
        sum += q;
      }
      if (sum > 1.0) {
        right = mid;
      } else {
        left = mid;
      }
    }
    ans[i] = left;
  }
  REP(i, n) {
    printf(" %.8f", ans[i] * 100.0);
  }
  puts("");
}
