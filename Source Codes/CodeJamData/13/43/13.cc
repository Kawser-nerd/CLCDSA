#include <iostream>
using namespace std;

int A[3000], B[3000], V[3000];

main() {
  int T, N, prob=1;
  for (cin >> T; T--;) {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    memset(V, 0, sizeof(V));
    for (int x = 1, pos; x <= N; x++) {
      for (pos = 0; pos < N; pos++) if (V[pos] == 0) {
        bool seen = (B[pos] == 1);
        for (int i = pos+1; i < N; i++) {
          if (V[i] == 0 && A[i] <= A[pos])
            goto posfail;
          if (V[i] != 0 && B[i] == B[pos]-1)
            seen = true;
        }
        if (!seen) goto posfail;
        break;
posfail:;
      }
      V[pos] = x;
    }
for (int i = 0; i < N; i++) {
  int a = 1;
  for (int j = 0; j < i; j++) if (V[j] < V[i]) a = max(a, A[j]+1);
  if (a != A[i]) cout << "A mismatch: " << a << ' ' << A[i] << endl;
}
for (int i = N-1; i >= 0; i--) {
  int b = 1;
  for (int j = N-1; j > i; j--) if (V[j] < V[i]) b = max(b, B[j]+1);
  if (b != B[i]) cout << "B mismatch: " << b << ' ' << B[i] << endl;
}
    cout << "Case #" << prob++ << ":";
    for (int i = 0; i < N; i++) cout << ' ' << V[i];
    cout << endl;
  }
}
