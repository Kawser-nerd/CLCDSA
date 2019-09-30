#include <iostream>
using namespace std;

int main() {
  long long N, M;
  cin >> N >> M;

  for (int i = 0; i <= N; ++i) {
    int j = 4*N - M - 2*i;
    int k = N-i-j;
    if (j >= 0 && k >= 0) {
      cout << i << " " << j << " " << k << endl;;
      return 0;
    }
  }
  cout << "-1 -1 -1" << endl;
}