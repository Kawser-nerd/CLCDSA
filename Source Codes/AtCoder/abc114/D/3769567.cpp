#include <iostream>
using namespace std;

int N;
int factor[105];

int f(int m) {
  int ret = 0;
  for (int i = 0; i < N; i++) {
    if (factor[i] >= m - 1) {
      ret++;
    }
  }
  return ret;
}

int main() {
  cin >> N;

  for (int i = 0; i <= N; i++) {
    factor[i] = 0;
  }

  for (int i = 2; i <= N; i++) {
    int n = i;
    for (int j = 2; j <= i; j++) {
      while (n % j == 0) {
        factor[j]++;
        n /= j;
      }
    }
  }

  int ans = f(75) + f(25) * (f(3) - 1) + f(15) * (f(5) - 1) +
            f(5) * (f(5) - 1) * (f(3) - 2) / 2;
  cout << ans << endl;
  return 0;
}