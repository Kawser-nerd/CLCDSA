#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> a(n), b(n), c(n);
  for (auto& i : a) cin >> i;
  for (auto& i : b) cin >> i;
  for (auto& i : c) cin >> i;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    auto ai = lower_bound(a.begin(), a.end(), b[i]);
	long long na = distance(a.begin(), ai);
    auto ci = upper_bound(c.begin(), c.end(), b[i]);
	long long nc = distance(ci, c.end());
	ans += na * nc;
  }
  cout << ans << endl;
  return 0;
}