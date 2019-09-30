#include <iostream>
#include <vector>

using namespace std;

#define int64 int_fast64_t

int64 t[101010];

int main() {
  int64 n, m, ans = 0;
  cin >> n >> m;
  for (int i=0; i<n; ++i) {
    int l, r, s;
    cin >> l >> r >> s;
    t[l-1] += s;
    t[r] -= s;
    ans += s;
  }

  for (int i=0; i<101000; ++i)
    t[i+1] += t[i];

  int64 mn = 1LL << 60;
  for (int i=0; i<m; ++i) {
    mn = min(mn, t[i]);
  }

  ans -= mn;
  cout << ans << endl;  

  return 0;
}