#include <iostream>
using namespace std;

int main()
{
  string s;
  cin >> s;
  size_t len = s.length();
  uint64_t count_b = 0;
  uint64_t ans = 0;
  for (auto i = 0; i < len; i++) {
    if (s[i] == 'B') {
      count_b++;
    } else {
      ans += count_b;
    }
  }
  cout << ans << endl;
}