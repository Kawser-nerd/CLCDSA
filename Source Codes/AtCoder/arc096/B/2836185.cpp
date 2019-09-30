#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;
// constexpr long long int INF = LLONG_MAX;
#define int long long int
vector<int> x;
vector<int> v;
int n, c;

int S(int x) {
  int res = 0;
  while (x != 0) {
    res += x % 10;
    x /= 10;
  }
  return res;
}

signed main() {
  cin >> n >> c;
  x.resize(n + 2);
  v.resize(n + 2);
  x[0] = 0;
  v[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> v[i];
  }
  x[n + 1] = c;
  v[n + 1] = 0;

  vector<int> max_a(n + 1);
  int mx = 0;
  int total = 0;
  for (int i = 0; i <= n; i++) {
    total += v[i];
    mx = max(mx, total - x[i]);
    max_a[i] = mx;
  }

  vector<int> max_b(n + 1);
  mx = 0;
  total = 0;
  for (int i = 0; i <= n; i++) {
    total += v[n + 1 - i];
    mx = max(mx, total - (c - x[n + 1 - i]));
    max_b[i] = mx;
  }

  int ans = 0;
  for (int i = 0; i < max_a.size(); i++) {
    ans = max(ans, max_a[i] - x[i] + max_b[n - i]); // ????
  }

  for (int i = 0; i < max_b.size(); i++) {
    ans = max(ans,
              max_b[i] - (c - x[n + 1 - i]) + max_a[n - i]); // ????
  }
  cout << ans << endl;
}