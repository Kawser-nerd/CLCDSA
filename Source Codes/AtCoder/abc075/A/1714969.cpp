#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a==b)
    cout << c;
  else if (a==c)
    cout << b;
  else
    cout << a;
}