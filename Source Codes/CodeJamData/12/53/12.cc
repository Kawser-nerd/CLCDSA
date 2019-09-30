#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1800000000000000000LL

long long m, f, n, no;
pair<long long, long long> po[220], p[220];

long long prod(long long a, long long b) {
  if (a > b) swap(a, b);

  if (a == 1) return b;
  if (a == 2 && b <= INF / 2) return 2 * b;
  if (a == 3 && b <= INF / 3) return 3 * b;
  if (b <= INF / a) return a * b;
  return INF;
}

long long calc(long long d) {
  long long res = 0, cm = m - d * f, prev = -1;
  for (int i = 0; i < n; i++) {
    long long amt = min(cm / p[i].first, prod(d, p[i].second - prev));
    if (amt == 0) break;

    res += amt;
    cm -= amt * p[i].first;

    prev = p[i].second;
  }
  return res;
}

int main() {
  int t; cin >> t;
  for (int c = 1; c <= t; c++) {
    cin >> m >> f >> no;
    for (int i = 0; i < no; i++) cin >> po[i].first >> po[i].second;
    sort(po, po+no);

    p[0] = po[0]; n = 1;
    for (int i = 1; i < no; i++) {
      if (po[i].second <= p[n-1].second) continue;
      p[n++] = po[i];
    }

    long long low = 1, hi = m / (p[0].first + f);
    while (hi - low > 3) {
      long long l = (2 * low + hi) / 3, r = (low + 2 * hi) / 3;
      long long fl = calc(l), fr = calc(r);
      if (fl >= fr) hi = r;
      else low = l;
    }

    long long res = 0;
    for (long long d = low; d <= hi; d++) res = max(res, calc(d));
    cout << "Case #" << c << ": " << res << endl;
  }
  return 0;
}
