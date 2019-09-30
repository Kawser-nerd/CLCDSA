#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  
  bool ok = true;

  for (int i=0; i<s.size(); ++i) {
    if (s.substr(i, 2) == "ch") {
      ++i;
    } else {
      switch(s[i]) {
          case 'o':
          case 'k':
          case 'u':
            break;
          default:
            ok &= false;
      }
    }
  }

  cout << (ok ? "YES":"NO") << endl;

  return 0;
}