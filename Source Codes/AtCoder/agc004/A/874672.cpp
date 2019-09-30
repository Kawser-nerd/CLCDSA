#include <algorithm>
#include <iostream>
using namespace std;

using int64 = long long;

int64 diff(int64 a, int64 b, int64 c) {
  if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0)
    return 0;
  return min(a * b, min(b * c, c * a));
}

int main() {
  int64 a, b, c;
  cin >> a >> b >> c;
  cout << diff(a, b, c) << "\n";
  return 0;
}