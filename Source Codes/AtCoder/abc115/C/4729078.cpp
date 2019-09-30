#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vec vector

int main(void)
{
  int n, k;
  cin >> n >> k;
  vec<int> h(n);
  rep(i, n) cin >> h[i];

  sort(h.begin(), h.end());
  int m = h[n - 1] - h[n - k];
  rep(i, n - k) {
    int t = h[i + k - 1] - h[i];
    if (t < m) m = t;
  }
  cout << m << endl;
  return 0;
}