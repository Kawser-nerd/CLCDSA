#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <cstdint>

using namespace std;
uint64_t gcd(uint64_t a, uint64_t b) {
	uint64_t r;
	while (0 < b) {
		r = a % b;
		a = b;
		b = r;
	}
  return a;
}

int main() {
  int n;
  cin >> n;
  uint64_t accum = 1;
  for (int i = 0; i < n; ++i) {
    uint64_t t;
    cin >> t;
    accum = accum / gcd(accum, t) * t;
  }
  std::cout << accum << endl;
}