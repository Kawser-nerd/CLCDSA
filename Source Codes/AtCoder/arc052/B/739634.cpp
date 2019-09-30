#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <complex>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <assert.h>
#include <array>
#include <cstdio>
#include <cstring>
#include <random>
#include <functional>
#include <numeric>
#include <bitset>
#include <fstream>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { cout << #a << " = " << a << endl; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }

typedef long long ll;

ll X[111], R[111], H[111];
double V[111];

double calc(int i, ll from) {
  const double h = X[i] + H[i] - from;
  const double ratio = h / H[i];
  return V[i] * ratio * ratio * ratio;  // ???
};

int main() {
  int N, Q; cin >> N >> Q;
  rep(i, N) cin >> X[i] >> R[i] >> H[i];
  rep(i, N) V[i] = acos(-1) * R[i] * R[i] * H[i] / 3.0;

  while(Q--) {
    ll L, R; cin >> L >> R;
    double res = 0.0;
    rep(i, N) {
      if(L <= X[i] + H[i]) res += calc(i, max(L, X[i]));
      if(R <= X[i] + H[i]) res -= calc(i, max(R, X[i]));
    }
    printf("%.10f\n", res);
  }

}