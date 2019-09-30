#include <iostream>
#include <vector>
using namespace std;

struct cake
{
  int64_t x, y, z;
};

int main()
{
  int n, m;
  cin >> n >> m;
  vector<cake> v(n);

  for (auto&& e : v) {
    cin >> e.x >> e.y >> e.z;
  }

  int64_t ans = 0;

  for (uint i = 0; i < 8; i++) {
    vector<int64_t> sum(n);
    int64_t a = (i & 1) == 0 ? 1 : -1;
    int64_t b = (i & 2) == 0 ? 1 : -1;
    int64_t c = (i & 4) == 0 ? 1 : -1;
    for (auto j = 0; j < n; j++) {
      sum[j] = a * v[j].x + b * v[j].y + c * v[j].z;
    }
    sort(begin(sum), end(sum), greater<>());
    int64_t x = 0;
    for (auto k = 0; k < m; k++) {
      x += sum[k];
    }
    ans = max(ans, x);
  }
  cout << ans << endl;
}