#include<iostream>

using namespace std;

int r[200000];
int X, K;

int main()
{
  int Q, T, A, minA, maxA, k = 0, t = 0, x = 0, sign = -1;

  cin >> X >> K;
  for(int i = 0; i < K; i++) {
    cin >> r[i];
  }
  r[K] = 2e9;

  minA = 0;
  maxA = X;
  cin >> Q;
  for(int i = 0; i < Q; i++) {
    cin >> T >> A;
    for(; T >= r[k]; ) {
      int diff = sign * (r[k] - t);
      x += diff;
      minA = min(X, max(0, minA + diff));
      maxA = min(X, max(0, maxA + diff));
      t = r[k];
      k++;
      sign *= -1;
    }
    T -= t;
    A = min(maxA, max(minA, A + x));
    A = min(X, max(0, A + sign * T));
    cout << A << endl;

    //cout << minA << " " << maxA << " " << x << " " << t << endl;
  }

  return 0;
}