#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <cstdlib>
#include <utility>

using namespace std;

int main() {
  int T; cin >> T;
  for(int tt = 1; tt <= T; tt++) {
    unsigned long long r, t;
    cin >> r >> t;

    unsigned long long lo = 0;
    unsigned long long hi = min(1100000000ULL, t / 2 / r);
    while(lo < hi) {
      unsigned long long md = (lo + hi + 1) / 2;
      if((2 * md + 2 * r - 1) * md <= t) {
        lo = md;
      } else {
        hi = md - 1;
      }
    }
    cout << "Case #" << tt << ": " << lo << endl;
  }
  return 0;
}
