#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int m, n, k, ct = 0;
double v[1001000];

double f(int idx) {
  double s = 0, p = 1, res = 0;
  for (int i = 0; i < idx; i++) {
    res += s * v[i];
    s = (s + p) * (1 - v[i]);
    p *= v[i];
  }
  for (int i = n-(k-idx); i < n; i++) {
    res += s * v[i];
    s = (s + p) * (1 - v[i]);
    p *= v[i];
  }
  // cout << idx << " " << res << endl;
  return res;
}

int main() {
  int t; cin >> t;
  for (int c = 1; c <= t; c++) {
    cin >> m >> k;
    n = 0;
    for (int i = 0; i < m; i++) {
      int a, b, c; string s; cin >> s >> c;
      // string s = "1/3"; int a, b, c = 100;

      int idx = s.find("/");
      a = atoi(s.substr(0, idx).data());
      b = atoi(s.substr(idx+1, s.size()-idx-1).data());

      for (int j = n; j < n+c; j++) v[j] = (1.0*a)/b;
      n += c;
    }

    sort(v, v+n, greater<double>());

    int low = 0, hi = k;
    while (hi - low > 2) {
      int left = (2*low + hi) / 3, right = (low + 2*hi) / 3;
      double fleft = f(left), fright = f(right);
      if (fleft > fright) low = left;
      else hi = right;
    }

    double res = 1;
    for (int i = max(0, low-1); i < min(k, hi+1); i++)
      res = min(res, f(i));
    cout << "Case #" << c << ": " << fixed << setprecision(8) << res << endl;
  }
  return 0;
}
