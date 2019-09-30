#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  long long x, y, z;
  cin >> x >> y >> z;
  auto ints = {x, y, z};
  if (any_of(ints.begin(), ints.end(), [](long long i){return i % 2 == 0;})) {
    cout << 0 << endl;
    return 0;
  }
  cout << min({x * y, y * z, x * z}) << endl;
  return 0;
}