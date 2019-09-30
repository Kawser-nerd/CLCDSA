#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq=1;qq<=tt;qq++) {
    printf("Case #%d: ", qq);
    long long n, p, ans;
    cin >> n >> p;
    long long total = 0;
    ans = 0;
    for (long long i=n-1;i>=0;i--) {
      total += (1LL << i);
      if (p <= total) break;
      ans += (i == 0 ? 1LL : (1LL << (n-i)));
    }
    cout << ans << " ";
    for (long long i=n;i>=0;i--)
      if (p >= (1LL << i)) {
        ans = (1LL << n) - (1LL << (n-i));
        break;
      }
    cout << ans << endl;
  }
  return 0;
}
