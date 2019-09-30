#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  a += b;
  int ans = stoi(a);
  ans <<= 1;
  cout << ans << endl;
  return 0;
}