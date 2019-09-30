#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
  long long n, k, a;
  long long total = 0;
  cin >> n >> k;
  for (long long i = 0; i < n; ++i) {
    cin >> a;
    total += a * min(min(i + 1, n - i), min(k, n - k + 1));
  }
  cout << total << endl;
  return 0;
}