#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
  int a, b, c;

  cin >> a >> b >> c;

  if (a + b == c || a + c == b || b + c == a) cout << "Yes" << endl;
  else                                        cout << "No" << endl;

  return 0;
}