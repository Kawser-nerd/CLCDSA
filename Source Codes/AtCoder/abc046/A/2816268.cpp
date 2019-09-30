#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
  int a, b, c;

  cin >> a >> b >> c;
  
  if (a == b && a == c && b == c)      cout << 1 << endl;
  else if (a != b && a != c && b != c) cout << 3 << endl;
  else                                 cout << 2 << endl;

  return 0;
}