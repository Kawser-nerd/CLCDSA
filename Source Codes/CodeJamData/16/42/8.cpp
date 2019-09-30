#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 222;

double p[MAX];

double calc(vector<double> p) {
  int n = p.size();
  int m = n/2;
  static double f[MAX][MAX];
  REP(i, n+1) REP(j, m+1) f[i][j] = 0;
  f[0][0] = 1.0;
  REP(i, n) REP(j, m + 1) {
    f[i + 1][j] += f[i][j] * (1 - p[i]);
    f[i + 1][j + 1] += f[i][j] * p[i];
  }
  return f[n][m];
}

int main(void) {
  int TC;
  scanf("%d", &TC);
  for (int tp = 1; tp <= TC; ++tp, fflush(stdout)) {
    int n, k;
    scanf("%d %d", &n, &k);
    REP(i, n) scanf("%lf", &p[i]);
    sort(p, p + n);

    double ans = 0;
    REP(i, k+1) {
      vector<double> v;
      REP(j, i) v.push_back(p[j]);
      REP(j, k-i) v.push_back(p[n-1-j]);
      ans = max(ans, calc(v));
    }

    printf("Case #%d: ", tp);
    printf("%.12lf\n", ans);
  }
  return 0;
}
