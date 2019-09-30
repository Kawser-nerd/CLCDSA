/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2015.04.18
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

void solve() {
  int n;
  cin >> n;
  int a[n];
  forn(i, n)
    cin >> a[i];

  int sum1 = 0, sum2 = 0, diff = 0;
  forn(i, n - 1)
    if (a[i + 1] < a[i]) {
      sum1 += a[i] - a[i + 1];
      diff = max(diff, a[i] - a[i + 1]);
    }
  forn(i, n - 1)
    sum2 += min(a[i], diff);
  printf("%d %d\n", sum1, sum2);
}

int main() {
  int tn;
  scanf("%d", &tn);
  forn(t, tn) {
    printf("Case #%d: ", t + 1);
    solve();
  }
  return 0;
}
