#include <iostream>
using namespace std;

main() {
  int T, N, S, P, pt, prob=1;
  for (cin >> T; T--;) {
    cin >> N >> S >> P;
    int n1 = 0, n2 = 0;
    for (int i = 0; i < N; i++) {
      cin >> pt;
      if (pt >= P + max(0, P-1) + max(0, P-1)) {
        n1++;
      } else if (pt >= P + max(0, P-2) + max(0, P-2)) {
        n2++;
      }
    }
    cout << "Case #" << prob++ << ": " << n1 + min(n2, S) << endl;
  }
}
