#include <cstdio>
#include <iostream>
using namespace std;

main() {
  int T, prob=1;
  for (cin >> T; T--;) {
    double C, F, X;
    cin >> C >> F >> X;
    double ret = X/2;
    double cur = 0, rate = 2;
    for (int f = 0; ; f++) {
      cur += C/rate;
      rate += F;
      ret = min(ret, cur + X/rate);
      if (cur > ret) break;
    }
    printf("Case #%d: %.7lf\n", prob++, ret);
  }
}
