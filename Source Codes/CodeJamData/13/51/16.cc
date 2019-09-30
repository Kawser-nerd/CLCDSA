#include <algorithm>
#include <cassert>
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
#define debug(x) cerr << #x << " = " << (x) << endl;
#define ALL(x) (x).begin(), (x).end()

bool can_target(vector<int64> bets, int64 B, int K, int64 target, int64 &invested) {
  invested = 0;
  for (int i=0; i<K; ++i) {
    assert(target >= bets[i]);
    invested += target - bets[i];
  }
  for (int i=K; i<37; ++i) {
    invested += max(0LL, target + 1 - bets[i]);
  }
  return B >= invested;
}

double calc(vector<int64> bets, int64 B, int K) {
  // debug(K);
  int64 lo = bets[K-1], hi = 1000000000000LL + B;
  int64 invested;
  while (lo < hi) {
    int64 mid = (lo + hi + 1) / 2;
    if (can_target(bets, B, K, mid, invested)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }

  if (!can_target(bets, B, K, lo, invested)) {
    return 0.0;
  }

  // debug(lo);
  int64 my_bets = 0;
  for (int i=0; i<K; ++i) {
    my_bets += lo - bets[i];
  }
  // debug(my_bets);

  double ret = 36.0 / K * my_bets - invested;
  // debug(ret);
  return ret;
}

int main() {
  cin.sync_with_stdio(0);

  int T;
  cin >> T;
  for (int tt=1; tt<=T; ++tt) {
    int64 B; int N;
    cin >> B >> N;
    vector<int64> bets(37, 0);
    for (int i=0; i<N; ++i) {
      cin >> bets[i];
    }
    sort(ALL(bets));

    double ans = 0;
    for (int K=1; K<37; ++K) {
      makemax(ans, calc(bets, B, K));
    }
    printf("Case #%d: %.10f\n", tt, ans);
  }

  return 0;
}
