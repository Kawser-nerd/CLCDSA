#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

int main() {
  int n;
  std::string s;
  std::cin >> n >> s;
  int ans = n;
  int a = 0;
  int b = 0;
  for (int i = 0; i < n; ++i) b += s[i] == 'E' ? 1 : 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'E') --b;
    if (i > 0 and s[i - 1] == 'W') ++a;
    ans = std::min(ans, a + b);
  }
  std::cout << ans << std::endl;
  return 0;
}