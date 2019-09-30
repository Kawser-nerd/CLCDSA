#include <array>
#include <iostream>
#include <numeric>

using namespace std;

int main() {
  array<int, 3> l;
  cin >> l[0] >> l[1] >> l[2];
  cout << accumulate(l.begin() + 1, l.end(), *l.begin(), bit_xor<int>())
       << endl;
}