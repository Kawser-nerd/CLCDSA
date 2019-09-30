#include <iostream>
#include <climits>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  int m[N];
  int lower = numeric_limits<int>::max();
  for (int i = 0; i < N; ++i) {
    cin >> m[i];
    X -= m[i];
    if (lower > m[i]) lower = m[i];
  }
  cout << N + X / lower << '\n';
  return 0;
}