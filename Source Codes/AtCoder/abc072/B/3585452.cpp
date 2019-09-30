#include <iostream>
#include <math.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i += 2) cout << s[i];
  cout << '\n';
  return 0;
}