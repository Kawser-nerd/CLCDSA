#include <iostream>
#include <string>

using namespace std;

int main()
{
  string s; cin >> s;
  int ans;

  int len = s.length();

  // A???
  for (int i = 0; i < len; i++) {
    if (s[i] == 'A') {
      for (int j = len - 1; j >= 0; j--) {
        if (s[j] == 'Z') {
          ans = (j - i) + 1;
          break;
        }
      }
      // ??????for?????
      if (ans != 0) break;
    }
  }

  cout << ans << endl;

  return 0;
}