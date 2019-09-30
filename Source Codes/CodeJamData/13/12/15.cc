#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int E, R, N;
int V[20000];

unsigned long long doit(int a, int ae, int b, int be) {
  if (b == a) return 0;
  int mx = -1, mxi = 0;
  for (int i = a; i < b; i++) {
    if (V[i] > mx) {mx = V[i]; mxi = i;}
  }
  int i = mxi;
  long long tope = ((long long)ae + (long long)(i-a)*R);
  if (tope > E) tope = E;
  long long bote = ((long long)be - (long long)(b-i)*R);
  if (bote < 0) bote = 0;
  return (unsigned long long)(tope-bote)*V[i] + doit(a, ae, i, tope) + doit(i+1, bote+R, b, be);
}

main() {
  int T, prob=1;
  for (cin >> T; T--;) {
    cin >> E >> R >> N;
    if (R > E) R = E;
    for (int i = 0; i < N; i++) cin >> V[i];
    cout << "Case #" << prob++ << ": " << doit(0, E, N, 0) << endl;
  }
}
