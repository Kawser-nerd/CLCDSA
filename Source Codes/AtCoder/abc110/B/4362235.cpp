#include<iostream>
#include <limits>
using namespace std;

int main() {
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  int x[N], y[M];
  int max_x{numeric_limits<int>::min()}, min_y{numeric_limits<int>::max()};
  for (int i{}; i < N; ++i) {
    cin >> x[i];
    if (max_x < x[i]) {
      max_x = x[i];
    }
  }
  for (int i{}; i < M; ++i) {
    cin >> y[i];
    if (min_y > y[i]) {
      min_y = y[i];
    }
  }

  bool ans = max_x < min_y && X < max_x && min_y <= Y;

  cout << (ans ? "No War" : "War") << endl;
  return 0;
}