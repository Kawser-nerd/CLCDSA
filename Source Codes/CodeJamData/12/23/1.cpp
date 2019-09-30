#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
pair<ll, int> sums[1<<23];
ll sums2[1<<23];

int main()
{
  int T; cin >> T;
  for (int ti = 1; ti <= T; ti++) {
    int N; cin >> N;
    ll A[511];
    ll a = -1, b;
    for (int i = 0; i < N; i++) cin >> A[i];
    int AN = N;
    if (N > 46) N = 46;
    while (a == -1) {
      random_shuffle(A, A+AN);
      int N2 = N/2;
      cerr << "trying " << N2 << endl;
      for (int i = 1; i < (1<<N2); i++) {
        int p = i&-i;
        sums[i].first = sums[i^p].first + A[__builtin_ctz(p)];
        sums[i].second = i;
      }
      sort(sums, sums+(1<<N2));
      for (int i = 1; i < (1<<N2); i++) {
        int p = i&-i;
        sums2[i] = sums2[i^p] + A[N2 + __builtin_ctz(p)];
        int x = lower_bound(sums, sums+(1<<N2), make_pair(sums2[i], 0)) - sums;
        if (x < (1<<N2) && sums[x].first == sums2[i]) {
          a = sums[x].second;
          b = (ll(i) << N2);
        }
      }
    }

    cerr << ti << endl;
    printf("Case #%d:\n", ti);
    if (a == -1) puts("Impossible");
    else {
      bool f = true;
      for (int i = 0; i < N; i++) {
        if (a & (1LL<<i)) {
          if (!f) cout << " "; f = false;
          cout << A[i];
        }
      }
      cout << endl;
      f = true;
      for (int i = 0; i < N; i++) {
        if (b & (1LL<<i)) {
          if (!f) cout << " "; f = false;
          cout << A[i];
        }
      }
      cout << endl;
    }
  }
}
