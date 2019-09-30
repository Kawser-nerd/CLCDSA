#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;

int main(void) {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int A, B; cin >> A >> B;
    double cum_p = 1.0;
    double ans = B+2;
    for (int i = 1; i <= A; i++) {
      double p; cin >> p;
      cum_p *= p;
      ans = min(ans, (A-i) + (B-i) + 1 + (B+1) * (1-cum_p));
    }
    printf("Case #%d: %.6f\n", t, ans);
  }
}
