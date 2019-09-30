#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int n, q, l, r, t;
  int a[100];
  cin >> n >> q;
  fill(a, a + n, 0);
  for (int qi = 0; qi < q; ++qi) {
    cin >> l >> r >> t;
    fill(a + l - 1, a + r, t);
  }
  for (int i = 0; i < n; ++i) {
    cout << a[i] << endl;
  }
  return 0;
}