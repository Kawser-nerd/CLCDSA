#include <iostream>
using namespace std;

constexpr int MAX_C = 1000;

int main() {
  int N, T;
  cin >> N >> T;
  int smallest{numeric_limits<int>::max()};
  for (int i{}; i < N; ++i) {
    int c, t;
    cin >> c >> t;
    if (t <= T && c < smallest) {
      smallest = c;
    }
  }

  cout << (smallest <= MAX_C ? to_string(smallest) : "TLE") << endl;
  return 0;
}