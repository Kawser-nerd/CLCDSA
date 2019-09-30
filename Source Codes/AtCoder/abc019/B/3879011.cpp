#include <iostream>
#include <string>
using namespace std;

int main() {
  string s, ans = "";
  cin >> s;
  int cnt = 1;
  for (int i=0; i<s.size()-1; ++i) {
    if (s[i] == s[i+1]) {
      cnt++;
    } else {
      ans += s[i] + to_string(cnt);
      cnt = 1;
    }
  }
  ans += s.back() + to_string(cnt);

  cout << ans << endl;
  return 0;
}