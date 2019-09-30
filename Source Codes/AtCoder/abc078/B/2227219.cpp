#include <iostream>
using namespace std;

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  x -= z;
  cout << x/(y+z) << endl;
}