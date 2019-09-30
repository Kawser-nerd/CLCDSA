#include <iostream>
using namespace std;

int main() {
  int N, T;
  cin >> N >> T;

  bool flag = false;
  int c, t, min_c = 1000;
  for (int i = 0; i < N; i++) {
    cin >> c >> t;
    if (min_c >= c && T >= t) {
      min_c = c;
      flag  = true;
    }
  }

  if (flag) {
    cout << min_c << endl;
  } else {
    cout << "TLE" << endl;
  }

  return 0;
}