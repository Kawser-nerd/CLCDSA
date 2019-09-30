#include <iostream>
using namespace std;

main() {
  int T, A, B, prob = 1;
  for (cin >> T; T--;) {
    cin >> A >> B;
    int p10 = 1, ret = 0;
    while (p10 * 10 <= A) p10 *= 10;
    for (int x = A; x <= B; x++) {
      int y = x;
      do {
        if (y > x && y <= B) ret++;
        y = y/10 + p10 * (y%10);
      } while (y != x);
    }
    cout << "Case #" << prob++ << ": " << ret << endl;
  }
}
