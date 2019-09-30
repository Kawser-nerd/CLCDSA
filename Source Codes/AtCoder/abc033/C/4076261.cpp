#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main() {
  string s; cin >> s;

  // *????????????????
  // vector??????
  // *????????????
  int ans = 0; bool ok = false;
  for (int si=0; si<s.size(); ++si) {
    if (s[si] == '+') {
      if (!ok) ++ans;
      ok = false;
    } else if (s[si] == '0') {
      ok = true;
    }
  }
  if (!ok) ++ans;
  cout << ans << endl;
  
  return 0;
}