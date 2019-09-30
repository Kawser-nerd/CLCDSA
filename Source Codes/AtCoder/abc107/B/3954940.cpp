#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<string> A(105);
  bool erase_x[105] = {}, erase_y[105] = {};
  for (int i = 0; i < H; i++) {
    cin >> A[i];
    if (A[i].find('#') == string::npos)
      erase_y[i] = true;
  }

  for (int j = 0; j < W; j++) {
    erase_x[j] = true;
    for (int i = 0; i < H; i++) {
      if (A[i][j] == '#') {
        erase_x[j] = false;
        break;
      }
    }
  }

  for (int i = 0; i < H; i++) {
    if (!erase_y[i]) {
      for (int j = 0; j < W; j++) {
        if (!erase_x[j])
          cout << A[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}