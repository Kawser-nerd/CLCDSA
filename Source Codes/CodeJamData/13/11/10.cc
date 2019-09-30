#include <cmath>
#include <iostream>
using namespace std;

main() {
  int T, prob=1;
  for (cin >> T; T--;) {
    long long r, t;
    cin >> r >> t;
    long long lo = 0, hi = 1e15;
    while (hi > lo) {
      long long N = (hi+lo+1)/2;
      if ((double)N * (1 + 2*r + (2*N-2)) > t+1e18 ||
          N * (1 + 2*r + (2*N-2)) > t)
        hi = N-1;
      else
        lo = N;
    }
    cout << "Case #" << prob++ << ": " << lo << endl;
  }
}
