#include <iostream>
#include <algorithm>
using namespace std;

struct st {
  int L, p, i;

  bool operator<(const st& o) const {
    if (L*o.p != p*o.L) return L*o.p < p*o.L;
    return i < o.i;
  }
};

st a[1010];

int main() {
  int t; cin >> t;
  for (int c = 1; c <= t; c++) {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].L;
    for (int i = 0; i < n; i++) { cin >> a[i].p; a[i].i = i; }
    sort(a, a+n);
    cout << "Case #" << c << ":";
    for (int i = 0; i < n; i++) cout << " " << a[i].i;
    cout << endl;
  }
  return 0;
}
