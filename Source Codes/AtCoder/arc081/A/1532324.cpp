#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<long> a(n);
  for (auto& e : a) {
    cin >> e;
  }

  sort(a.begin(), a.end(), greater<long>());

  long l = 0;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == a[i+1]) {
      if (l != 0) {
        cout << l * a[i] << endl;
        return 0;
      }
      l = a[i];
      i++;
    }
  }
  cout << 0 << endl;
  return 0;
}