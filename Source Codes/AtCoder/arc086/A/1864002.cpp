#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (auto& e : a)
    cin >> e;

  map<int, int> c;

  for (auto e : a) {
    c[e] += 1;
  }

  vector<int> cv;
  for (auto& e : c) {
    cv.push_back(e.second);
  }

  if (k >= cv.size()) {
    cout << 0 << endl;
	return 0;
  }

  sort(cv.begin(), cv.end());
  int ans = 0;
  for (int i = 0; i < cv.size() - k; i++) {
    ans += cv[i];
  }

  cout << ans << endl;
  return 0;
}