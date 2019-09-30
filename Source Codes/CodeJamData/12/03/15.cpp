#include <iostream>

using namespace std;

int cycle(int a, int lPlace) {
  return lPlace*(a % 10) + (a / 10);
  }

int main() {
  int nc; cin >> nc;
  for (int cur = 1; cur <= nc; ++cur) {
    int a, b; cin >> a >> b;

    int lPlace = 1;
    while (lPlace*10 <= a) lPlace *= 10;

    int count = 0;
    for (int i = a; i <= b; ++i) {
      int tCount = 0, j = i;
      do {
        if ((a <= j) && (j <= b)) ++tCount;
        j = cycle(j, lPlace);
        }
      while (j != i);

      count += tCount - 1;
      }

    cout << "Case #" << cur << ": " << (count / 2) << '\n';
    }
  }
