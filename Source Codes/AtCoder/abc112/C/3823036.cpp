#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;

  int XYH[N + 5][3], ca;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> XYH[i][j];
    }
    if (XYH[i][2] > 0)
      ca = i;
  }

  for (int x = 0; x <= 1000; x++) {
    for (int y = 0; y <= 1000; y++) {
      bool flag = true;
      int H     = XYH[ca][2] + abs(XYH[ca][0] - x) + abs(XYH[ca][1] - y);
      for (int i = 0; i < N; i++) {
        int h = max(H - abs(XYH[i][0] - x) - abs(XYH[i][1] - y), 0);
        if (XYH[i][2] != h) {
          flag = false;
          break;
        }
      }

      if (flag) {
        cout << x << " " << y << " " << H << endl;
        return 0;
      }
    }
  }
  return 0;
}