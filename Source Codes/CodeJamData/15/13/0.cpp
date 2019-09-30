/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2015.04.18
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

long double eps = 1e-15;

void solve() {
  int n;
  cin >> n;
  int x[n], y[n];
  forn(i, n)
    cin >> x[i] >> y[i];
  long double a[2 * n];
  forn(i, n) {
    int an = 0, ans = n - 1;
    forn(j, n)
      if (j != i)
        a[an++] = atan2l(y[j] - y[i], x[j] - x[i]);
    sort(a, a + an);
    forn(i, an)
      a[i + an] = a[i] + 2 * M_PI;
/*
    forn(i, 2 * an)
      printf("%.3f ", (double)a[i]);
    puts("");
*/
    int l = 0, r = 0;
    forn(i, an) {
      while (l + 1 < 2 * an && a[l] - a[i] < eps)
        l++;
      while (r < 2 * an && a[r] - a[i] < M_PI - eps)
        r++;
      ans = min(ans, r - l);
    }
    printf("%d\n", ans);
  }
}

int main() {
  int tn;
  scanf("%d", &tn);
  forn(t, tn) {
    printf("Case #%d:\n", t + 1);
    fprintf(stderr, "Case #%d:\n", t + 1);
    solve();
  }
  return 0;
}
