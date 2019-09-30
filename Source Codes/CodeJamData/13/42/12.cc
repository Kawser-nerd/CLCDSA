#include <algorithm>
#include <iostream>
using namespace std;

long long doit1(long long N, long long P) {
  if (N == 1) return 0;
  if (P <= N/2) return 0;
  long long x = doit1(N/2, P-N/2);
  return min(N-1, x*2 + 2);
}

long long doit2(long long N, long long P) {
  if (N == 1) return 0;
  if (P == N) return N-1;
  if (P >= N/2) return N-2;
  long long x = doit2(N/2, P);
  return x*2;
}

main() {
  long long T, N, P, prob=1;
  for (cin >> T; T--;) {
    cin >> N >> P;
    cout << "Case #" << prob++ << ": "
         << doit1(1LL << N, P) << ' '
         << doit2(1LL << N, P) << endl;
  }
}
