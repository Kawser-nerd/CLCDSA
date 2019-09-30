/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define sz(a) (int)(a).size()

typedef pair <int, int> pii;

void cor( vector<pii> &a ) {
  int k = 0;
  sort(a.begin(), a.end());
  forn(i, sz(a)) {
    while (k > 0 && a[i].second >= a[k - 1].second)
      k--;
    a[k++] = a[i];
  }    
  a.resize(k);
}

const double inf = 1e100;
const int N = 503;

int n, y;
double f[N][N];

double get( double t0, pii p ) {
  return (t0 * p.second + p.first) / (y - p.second);
}

void relax( int i, int j, double F ) {
  f[i][j] = min(f[i][j], F);
}

void solve() {
  cin >> y >> n;
  int s[n], p[n];
  forn(i, n) cin >> p[i];
  forn(i, n) cin >> s[i];
  vector<pii> a, b;
  forn(i, n)
    (p[i] < 0 ? a : b).push_back(pii(abs(p[i]), s[i]));
  cor(a);
  cor(b);
  forn(i, sz(a) + 1)
    forn(j, sz(b) + 1)
      f[i][j] = inf;
  f[0][0] = 0;
  double ans = inf;
  forn(i, sz(a) + 1)
    forn(j, sz(b) + 1) {
      double ma = 0, F = f[i][j];
      for (int k = j; k < sz(b); k++) {
        ma = max(ma, get(F, b[k]));
        relax(i, k + 1, F + 2 * ma);
      } 
      if (i == sz(a)) 
        ans = min(ans, F + ma);

      ma = 0;
      for (int k = i; k < sz(a); k++) {
        ma = max(ma, get(F, a[k]));
        relax(k + 1, j, F + 2 * ma);
      } 
      if (j == sz(b)) 
        ans = min(ans, F + ma);
    }
  printf("%.15f\n", ans);
}

int main() {
  int tn;
  scanf("%d", &tn);
  forn(t, tn) {
    fprintf(stderr, "Case #%d:\n", t + 1);
    printf("Case #%d: ", t + 1);
    solve();
  }
  return 0;
}
