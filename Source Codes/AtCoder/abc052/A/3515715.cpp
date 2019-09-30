#include <iostream>

using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int f, s;
  f = a * b;
  s = c * d;
  if(f < s) {
    cout << s << endl;
  } else {
    cout << f << endl;
  }
  return 0;
}