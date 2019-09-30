#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int t; cin >> t;
  for (int test = 1; test <= t; ++test) {
    double c, f, x; cin >> c >> f >> x;

    double num_farms = (x*f/c - 2)/f;
    int nn = num_farms;
    if (nn < 0) nn = 0;

    double mult = 0;
    for (int i = 0; i < nn; ++i) {
      mult += 1.0 / (2.0 + i * f);
    }
    double answer = (c * mult) + (x / (2 + nn * f));

    cout << "Case #" << test << ": "
         << fixed << setprecision(7) << answer << endl;
  }
  return 0;
}