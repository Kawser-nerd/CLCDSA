#include <iostream>
#include <math.h>
using namespace std;
int main() {
  long N; cin >> N;
  for (int s = sqrt(N); s > 0; --s) {
    if ((N / s) * s == N) {
      N /= s;
      break;
    }
  }
  int digits{0};
  while (N > 0) {
    ++digits;
    N /= 10;
  }

  cout << digits << "\n";
  return 0;
}