#include <iostream>
#include <string>
using namespace std;

int main() {
  string str, ans;
  cin >> str;
  for (auto s : str) {
    if (s != 'B')
      ans += s;
    else if (!ans.empty()) {
      auto it = ans.end();
      ans.erase(--it);
    }
  }
  cout << ans << endl;
  return 0;
}