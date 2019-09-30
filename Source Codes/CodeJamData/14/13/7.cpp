#include <iostream>
#include <vector>

using namespace std;

int property_x(const vector<int>& a) {
  int ret = 0;
  for (int i = 0; i < int(a.size()); ++i) {
    if (a[i] > i) ++ret;
  }
  return ret;
}

int main() {
  int T;
  cin >> T;
  for (int ca = 1; ca <= T; ++ca) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << "Case #" << ca << ": ";
    if (property_x(a) < 515) cout << "GOOD" << endl;
    else cout << "BAD" << endl;
  }
}

