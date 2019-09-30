#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int N;
  cin >> N;
  double T, A;
  cin >> T >> A;
  int H[N];
  cin >> H[0];
  double nearest{T - H[0] * 0.006};
  int ans{0};
  for (int i{1}; i < N; ++i) {
    cin >> H[i];
    double t = T - H[i] * 0.006;
    if (abs(nearest - A) > abs(t - A)) {
      nearest = t;
      ans = i;
    }
  }

  cout << ans + 1 << endl;
  return 0;
}