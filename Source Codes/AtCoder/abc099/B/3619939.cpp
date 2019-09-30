#include <iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  int n = b - a - 1;
  cout << n * (n + 1) / 2 - a << endl;
  return 0;
}