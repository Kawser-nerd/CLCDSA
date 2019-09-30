#include <iostream>
using namespace std;

int main() {
  int N, M, T[100], P[100], X[100];
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> T[i];
  }
  cin >> M;
  for (int i = 0; i < M; ++i) {
    cin >> P[i] >> X[i];
  }
  for (int i = 0; i < M; ++i) {
    int sum = 0;
    for (int j = 0; j < N; ++j) {
      sum += P[i] - 1 == j ? X[i] : T[j];
    }
    cout << sum << endl;
  }
  return 0;
}