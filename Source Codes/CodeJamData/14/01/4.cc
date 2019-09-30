#include <iostream>
using namespace std;

int g1[4][4], g2[4][4];

main() {
  int T, prob=1;
  for (cin >> T; T--;) {
    int ret = -1;
    int r1, r2;
    cin >> r1;
    for (int y = 0; y < 4; y++)
    for (int x = 0; x < 4; x++) {
      cin >> g1[y][x];
    }
    cin >> r2;
    for (int y = 0; y < 4; y++)
    for (int x = 0; x < 4; x++) {
      cin >> g2[y][x];
    }
    for (int v = 1; v <= 16; v++) {
      int x;
      for (x = 0; x < 4; x++) if (g1[r1-1][x] == v) break;
      if (x == 4) continue;
      for (x = 0; x < 4; x++) if (g2[r2-1][x] == v) break;
      if (x == 4) continue;
      if (ret != -1) ret = -2; else ret = v;
    }

    cout << "Case #" << prob++ << ": ";
    if (ret == -1) {
      cout << "Volunteer cheated!" << endl;
    } else if (ret == -2) {
      cout << "Bad magician!" << endl;
    } else {
      cout << ret << endl;
    }
  }
}
