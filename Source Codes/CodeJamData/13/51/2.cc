#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

long long B;
double doit(const vector<long long>& X, const vector<long long>& Y) {
  long long n = 0;
  for (n = 1; n < 37; n++) {
    if (Y[n] != Y[n-1]) break;
  }
  long long winbets = 0;
  for (long long i = 0; i < n; i++) winbets += Y[i]-X[i];
  long long bets = winbets;
  for (long long i = n; i < 37; i++) bets += Y[i]-X[i];
  if (bets > B) return 0.0;
  return winbets*36.0/n - bets;
}

main() {
  long long T, N, prob=1;
  for (cin >> T; T--;) {
    cin >> B >> N;
    vector<long long> X(37);
    for (long long i = 0; i < N; i++) cin >> X[i];
    sort(X.begin(), X.end());
    vector<long long> Y = X;
    double ret = 0.0;
    long long curb = B;
    while (curb >= 0) {
      ret = max(ret, doit(X, Y));
      long long n;
      for (n = 1; n < 37; n++) {
        if (Y[n] != Y[n-1]) break;
      }
      if (n == 37) break;
      long long x = Y[n] - Y[0];
      if (curb >= x*n) {
        for (long long i = 0; i < n; i++) Y[i] += x-1;
        curb -= (x-1) * n;
        ret = max(ret, doit(X, Y));
        for (long long i = n-1; i >= 0; i--) {
          Y[i]++;
          curb--;
          ret = max(ret, doit(X, Y));
        }
      } else {
        x = curb / n - 1;
        if (x < 0) x = 0;
        for (long long i = 0; i < n; i++) Y[i] += x;
        curb -= x*n;
        ret = max(ret, doit(X, Y));
        for (long long i = n-1; i >= 0; i--) {
          Y[i]++;
          curb--;
          if (curb < 0) break;
          ret = max(ret, doit(X, Y));
        }
        for (long long i = n-1; i >= 0; i--) {
          Y[i]++;
          curb--;
          if (curb < 0) break;
          ret = max(ret, doit(X, Y));
        }
      }
    }
    printf("Case #%lld: %.9lf\n", prob++, ret);
  }
}
