#include <iostream>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  bool directly = abs(a - c) <= d;
  bool indirectly = abs(a - b) <= d && abs(b - c) <= d;

  cout << ((directly || indirectly) ? "Yes" : "No") << endl;
}