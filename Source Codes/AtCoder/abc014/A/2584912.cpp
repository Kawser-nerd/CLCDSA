#include <iostream>
using namespace std;
int a, b;
int main() {
  cin >> a >> b;
  int ans = a % b != 0 ? b - (a % b) : 0;
  cout << ans << endl;
  return 0;
}