#include <iostream>
using namespace std;

int main() {
  int x, y, k; cin >> x >> y >> k; if (k <= y) cout << x + k << endl; else cout << x + y - (k - y) << endl;
  return 0;
}