#include <cstdio>
#include <vector>
#include <algorithm>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
#define RANGE(a, l, r) lower_bound(a, a + N, r) - lower_bound(a, a + N, l)
using namespace std;
typedef int ll;

ll N, A[200000], B[200000];
ll pow2[31], l1[29], r1[29], l2[29], r2[29];
ll moda[29][200000], modb[29][200000];

int main(void) {
  scanf("%d", &N);
  REP(i, 0, N) scanf("%d", &A[i]);
  REP(i, 0, N) scanf("%d", &B[i]);

  REP(i, 0, 31) pow2[i] = (1 << i);
  REP(i, 0, 29) {
    l1[i] = pow2[i];
    r1[i] = pow2[i + 1];
    l2[i] = pow2[i + 1] + pow2[i];
    r2[i] = pow2[i + 2];
  }
  REP(i, 0, 29) REP(j, 0, N) moda[i][j] = A[j] % pow2[i + 1];
  REP(i, 0, 29) {
    REP(j, 0, N) modb[i][j] = B[j] % pow2[i + 1];
    sort(modb[i], modb[i] + N);
  }

  ll ans = 0;
  REP(i, 0, N) {
    REP(k, 0, 29) {
      ll cnt = 0;
      cnt += RANGE(modb[k], l1[k] - moda[k][i], r1[k] - moda[k][i]);
      cnt += RANGE(modb[k], l2[k] - moda[k][i], r2[k] - moda[k][i]);
      if(cnt & 1) ans = ans ^ pow2[k];
    }
  }
  printf("%d\n", ans);
}