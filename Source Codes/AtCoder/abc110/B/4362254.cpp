#include<iostream>
#include <limits>
using namespace std;

int main() {
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  int x[N], y[M];
  for (int i{}; i < N; ++i) {
    cin >> x[i];
  }
  for (int i{}; i < M; ++i) {
    cin >> y[i];
  }
  sort(x, x + N);
  sort(y, y + M);

  bool ans = x[N-1] < y[0] && X < x[N-1] && y[0] <= Y;

  cout << (ans ? "No War" : "War") << endl;
  return 0;
}