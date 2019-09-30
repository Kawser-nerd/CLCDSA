#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.length();
  if (s.compare(n-1, 1, "T") == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;    
  }
  return 0;
}