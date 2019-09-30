#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s;
int main() {
  cin >> s;
  transform(s.begin(), s.begin() + 1, s.begin(), ::toupper);
  transform(s.begin() + 1, s.end(), s.begin() + 1, ::tolower);
  cout << s << endl;
  return 0;
}