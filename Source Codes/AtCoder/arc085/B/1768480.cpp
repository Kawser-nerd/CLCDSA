#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int n, z, w;
  cin >> n >> z >> w;

  vector<int> a(n);
  for (auto& e : a) cin >> e;

  if (n == 1) {
    cout << abs(a[0]-w) << endl;
    return 0;
  }

  cout << max(abs(a[n-1] - w), abs(a[n-1] - a[n-2])) << endl;
  return 0;
}