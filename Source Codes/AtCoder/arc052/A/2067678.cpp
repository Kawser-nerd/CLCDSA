// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  int ans = 0;
  for (char c : s) {
    if (c >= '0' && c <= '9') {
      ans = ans * 10 + (c - '0');
    }
  }
  cout << ans << endl;
	return 0;
}