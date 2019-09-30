#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a < b) {
    cout << c / a;
  } else {
    cout << c / b;
  }
  cout << endl;
}