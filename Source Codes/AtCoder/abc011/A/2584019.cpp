#include <iostream>
using namespace std;
int n;
int main() {
  cin >> n;
  int ans = n == 12 ? 1 : n + 1;
  cout << ans << endl;
  return 0;
}