#define NDEBUG
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

template<typename T, typename U> inline void makemax(T &res, const U &x) {
  if (x > res) {
    res = x;
  }
}
typedef long long int64;

double solve() {
  int n, p, q, r, s;
  cin >> n >> p >> q >> r >> s;
  vector<int64> y(n+1);
  for (int i=0; i<n; ++i) {
    y[i+1] = y[i] + (int64(i) * p + q) % r + s;
  }

  int64 best = 0;
  for (int a=0; a<n; ++a) {
    int bs = lower_bound(y.begin() + a, y.end(), y[n] - y[a]) - y.begin();
    for (int d=-3; d<=3; ++d) {
      int b = bs + d - 1;
      if (b < a || b >= n) {
        continue;
      }
      int64 left = y[a], mid = y[b+1] - y[a], right = y[n] - y[b+1];
      int64 solveig = max(left, max(mid, right));
      int64 arnar = y[n] - solveig;
      makemax(best, arnar);
    }
  }

  return double(best) / y[n];
}

int main() {
  ios_base::sync_with_stdio(0);

  int T;
  cin >> T;
  for (int tt=1; tt<=T; ++tt) {
    printf("Case #%d: %.10f\n", tt, solve());
  }
}
