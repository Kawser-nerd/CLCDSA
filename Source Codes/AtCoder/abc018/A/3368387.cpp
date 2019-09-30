#include <iostream>

using namespace std;

int main() {
  int a, b, c, d = 1, e = 1, f = 1;
  cin >> a >> b >> c;
  a < b ? ++d : ++e;
  a < c ? ++d : ++f;
  b < c ? ++e : ++f;
  cout << d << endl;
  cout << e << endl;
  cout << f << endl;
}