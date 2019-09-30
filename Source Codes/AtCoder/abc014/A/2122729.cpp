#include <iostream>
using namespace std;

int main() {
  int a, b, n;
  cin >> a;
  cin >> b;
  n = b - a%b;
  cout << n%b << endl;
  return 0;
}