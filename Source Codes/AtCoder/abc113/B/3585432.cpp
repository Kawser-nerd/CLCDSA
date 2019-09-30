#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int T, A;
  cin >> T >> A;
  int H[N];
  cin >> H[0];
  int index = 0;
  double temp = fabs(A - (T - H[0] * 0.006));
  for (int i = 1; i < N; ++i) {
    cin >> H[i];
    double temptemp = fabs(A - (T - H[i] * 0.006));
    if (temp > temptemp) {
      index = i;
      temp = temptemp;
    }
  }
  cout << index + 1 << '\n';
  return 0;
}