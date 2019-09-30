#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

typedef long long ll;

using namespace std;

int main (void) {
  int tn;
  scanf ("%d", &tn);
  for (int tt = 1; tt <= tn; tt++) {
    printf ("Case #%d: ", tt);

    int L;
    ll t;
    int N;
    int C;
    cin >> L >> t >> N >> C;
    vector <int> tmp(C);
    for (int i = 0; i < C; i++) {
      scanf ("%d", &tmp[i]);
    }
    vector <int> v(N);
    for (int i = 0; i < N; i++) {
      v[i] = tmp[i % C] * 2;
    }

    ll res = 0;
    for (int i = 0; i < N; i++) {
      ll x = min ((ll)v[i], t);
      v[i] -= x;
      t -= x;
      res += x;
    }
    sort (v.begin(), v.end());
    reverse (v.begin(), v.end());
    for (int i = 0; i < N; i++) {
      if (i < L) {
        res += v[i] / 2;
      } else {
        res += v[i];
      }
    }
    cout << res << endl;
  }
  return 0;
}