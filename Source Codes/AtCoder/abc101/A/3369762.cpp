#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = count(s.begin(), s.end(), '+');
  cout << n - (4 - n) << endl;
}