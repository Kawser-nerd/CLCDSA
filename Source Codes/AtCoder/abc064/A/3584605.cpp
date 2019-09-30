#include <iostream>
using namespace std;

int main() {
  int r, g, b;
  cin >> r >> g >> b;

  int num = r * 100 + g * 10 + b;

  cout << (num % 4 == 0 ? "YES\n" : "NO\n");

  return 0;
}