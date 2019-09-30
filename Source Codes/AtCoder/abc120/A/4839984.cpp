#include <iostream>
#include <algorithm>

using namespace std;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a, b, c;
  cin >> a >> b >> c;
  
  cout << min(b/a, c) << '\n';
}