#include <iostream>

using namespace std;

bool possible[16];

int main() {
  int t; cin >> t;
  for (int test = 1; test <= t; ++test) {
    for (int i = 0; i < 16; ++i) possible[i] = true;

    for (int times = 0; times < 2; ++times) {
    int row; cin >> row; row--;
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        int curr; cin >> curr; curr--;
        if (i != row) possible[curr] = false;
      }
    }
    }

    int num_solns = 0;
    int last = -1;
    for (int i = 0; i < 16; ++i) {
      if (possible[i]) {
        num_solns++;
        last = i;
      }
    }

    cout << "Case #" << test << ": ";

    if (num_solns == 0) {
      cout << "Volunteer cheated!";
    } else if (num_solns == 1) {
      cout << last+1;
    } else {
      cout << "Bad magician!";
    }
    cout << endl;
  }
  return 0;
}