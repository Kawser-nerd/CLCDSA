#include <iostream>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int c;
  c = abs(a - b);
  if (c <= 5)
    cout << c << endl;
  else
    cout << 10 - c << endl;
}