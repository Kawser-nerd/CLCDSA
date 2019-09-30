#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

void Solve() {
  double r, t;
  cin >> r >> t;

  int64_t low = 1, high = t;

  while (low + 1 < high) {
    int64_t mid = (low + high) / 2;

    if ((mid) * (-1 + 2 * mid + 2 * r) <= t) {
      low = mid;
    } else {
      high = mid;
    }
  }

  cout << low << endl;
}

int main() {
  int num_cases;
  cin >> num_cases;
  for (int i = 1; i <= num_cases; i++) {
    cout << "Case #" << i << ": ";
    Solve();
  }
}
