#include<iostream>

using namespace std;

int r[200000];
int X, K, Q, T, A, s, l;

int main()
{
  int k = 0, t = 0, x = 0, sign = -1;

  cin >> X >> K;
  for(int i = 0; i < K; i++) {
    cin >> r[i];
  }

  l = X;
  
  for(cin >> Q; Q; Q--) {
    cin >> T >> A;
    for(; k<K&T>=r[k]; ) {
      int diff = sign * (r[k] - t);
      x += diff;
      s = min(X, max(0, s + diff));
      l = min(X, max(0, l + diff));
      t = r[k];
      k++;
      sign *= -1;
    }
    T -= t;
    A = min(l, max(s, A + x));
    A = min(X, max(0, A + sign * T));
    cout << A << endl;
  }

  return 0;
}