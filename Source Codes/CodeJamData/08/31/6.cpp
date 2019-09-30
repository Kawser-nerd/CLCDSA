#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
using namespace std;

int main() {
  int N;
  scanf("%d", &N);

  for (int z = 1; z <= N; ++z) {
    int P, K, L;
    int freqs[2001];

    scanf("%d%d%d", &P, &K, &L);

    for (int i = 0; i < L; ++i) {
      scanf("%d", &freqs[i]);
    }

    sort(freqs, freqs + L, greater<int>());

    long long res = 0;

    for (int i = 0; i < L; ++i) {
      int presses = i / K + 1;

      res += (long long) presses * (long long) freqs[i];
    }

    cout << "Case #" << z << ": " << res << endl;
  }

  return 0;
}