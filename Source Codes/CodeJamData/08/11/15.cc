#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int T; scanf("%d", &T);
  for (int c = 1; c <= T; ++c) {
    int n; scanf("%d", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i)
      scanf("%d", &b[i]);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long s = 0;
    for (int i = 0; i < n; ++i) {
      long long t = a[i];
      t *= b[n-1-i];
      s += t;
      }
    printf("Case #%d: %lld\n", c, s);
    }
  }