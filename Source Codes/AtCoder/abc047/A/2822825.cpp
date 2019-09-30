#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

int main() {
  vector<int> s;

  for (int i = 0; i < 3; i++) {
    int x;
    cin >> x;
    s.push_back(x);
  }
  sort(s.begin(), s.end());

  if (s[0] + s[1] == s[2]) cout << "Yes" << endl;
  else                     cout << "No" << endl;

  return 0;
}