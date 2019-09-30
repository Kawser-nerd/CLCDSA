#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  s.pop_back();
  while (!s.empty()) {
    int len = s.length();
    if (s.substr(0, len/2) == s.substr(len/2, len) &&
	len % 2 == 0) {
      break;
    }
    s.pop_back();
  }
  cout << s.length() << endl;
}