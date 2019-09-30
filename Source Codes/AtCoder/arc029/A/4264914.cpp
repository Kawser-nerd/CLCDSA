#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int T[N];
  for (int i{}; i < N; ++i) {
    cin >> T[i];
  }

  int shorter{numeric_limits<int>::max()};
  for (int i{}; i < (1 << N); ++i) {
    int a{}, b{};
    for (int j{}; j < N; ++j) {
      if (i & (1 << j)) {
        a += T[j];
      } else {
        b += T[j];
      }
    }
    int larger = max(a, b);
    if (shorter > larger) {
      shorter = larger;
    }
  }

  cout << shorter << endl;
  return 0;
}