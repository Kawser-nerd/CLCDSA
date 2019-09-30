#include <cmath>
#include <iostream>
using ll = long long int;
int main(void) {
  int n;
  int ans = 0;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    ll x;
    std::cin >> x;
    int c = 0;
    while (x % 2 == 0) {
      x /= 2;
      c++;
    }
    ans += c;
  }
  std::cout << ans << std::endl;
  return 0;
}