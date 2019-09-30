#include <iostream>
using namespace std;

int main() {
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;

  int tmp, x_max = -100, y_min = 100;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    x_max = max(tmp, x_max);
  }
  for (int i = 0; i < M; i++) {
    cin >> tmp;
    y_min = min(tmp, y_min);
  }

  if (x_max < y_min && x_max >= X && y_min <= Y)
    cout << "No War" << endl;
  else
    cout << "War" << endl;
  return 0;
}