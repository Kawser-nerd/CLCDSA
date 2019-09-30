#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int nc; cin >> nc;
  for (int cur = 1; cur <= nc; ++cur) {
    int n, s, p; cin >> n >> s >> p;

    int min_surprise = p + 2*max(0, p-2);
    int min_no_surprise = p + 2*max(0, p-1);

    int pass = 0;
    for (int i = 0; i < n; ++i) {
      int total; cin >> total;
      if (min_surprise <= total) {
        if (min_no_surprise <= total)
          ++pass;
        else if (s) {
          --s; ++pass;
          }
        }
      }

    cout << "Case #" << cur << ": " << pass << '\n';
    }
  }
