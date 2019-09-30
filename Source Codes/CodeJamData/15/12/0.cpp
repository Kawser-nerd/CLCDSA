/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2015.04.18
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

void solve() {
  int b, n;
  cin >> b >> n;
  int m[b];
  forn(i, b) {
    cin >> m[i];
    assert(m[i] > 0);
  }

  ll l = 0, r = 1e18, x;
  //puts("x");
  while (l < r) {
    x = (l + r) / 2;
    ll sum = 0;
    forn(i, b)
      sum += x / m[i] + 1;
    if (sum >= n)
      r = x;
    else
      l = x + 1;
  }
  //puts("x");
  ll sum = 0;
  vector<int> ind;
  forn(i, b) {
    sum += l / m[i] + 1;
    if (l % m[i] == 0)
      ind.push_back(i);
  }
  //puts("x");
  //printf("n = %d, sum = %I64d, ind = %d\n", n, sum, ind.size());
  printf("%d\n", ind.at(ind.size() - 1 - (sum - n)) + 1);
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
