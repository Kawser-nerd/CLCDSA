#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

#define repeat(n) for (int repc = (n); repc > 0; --repc)
template<typename T, typename U> inline void makemin(T &res, const U &x) {
  if (x < res) {
    res = x;
  }
}
template<typename T, typename U> inline void makemax(T &res, const U &x) {
  if (x > res) {
    res = x;
  }
}

const int Tmax = 1000000;
int n;
vector<int> times;

bool can(const double K, const double E) {
  double tmin = -HUGE_VAL, tmax = HUGE_VAL;
  double dk = 0;
  for (int i=0; i<n; ++i, dk += K) {
    makemax(tmin, times[i] - E - dk);
    makemin(tmax, times[i] + E - dk);
  }
  return tmin <= tmax;
}

double calc(const double K) {
  double lo = 0, hi = n * K;
  repeat (100) {
    double E = (lo + hi) / 2;
    if (can(K, E)) {
      hi = E;
    } else {
      lo = E;
    }
  }
  return lo;
}

double solve1() {
  cin >> n;
  times.resize(n);
  for (int &t : times) {
    cin >> t;
  }

  double lo = 0, hi = Tmax;
  repeat (150) {
    double d = hi - lo;
    double k1 = lo + d/3, k2 = lo + 2*d/3;
    if (calc(k1) < calc(k2)) {
      hi = k2;
    } else {
      lo = k1;
    }
  }
  return calc(lo);
}

int main() {
  cin.sync_with_stdio(0);

  int T; cin >> T;
  for (int tt=1; tt<=T; ++tt) {
    printf("Case #%d: %.12f\n", tt, solve1());
  }

  return 0;
}
