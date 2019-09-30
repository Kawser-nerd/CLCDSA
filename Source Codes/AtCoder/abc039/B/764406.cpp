#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int x;
  cin >> x;
  for (int n = 1; true; ++n) {
    if (n * n * n * n == x) {
      cout << n << endl;
      return 0;
    }
  }
}