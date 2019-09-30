#define DEBUG 0

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

int N, best;
long long m[100];

void f(int pos, long long A, int ops) {
  //if(DEBUG) printf("pos = %d, cur = %lld, e = %lld\n", pos, cur, e);
  if(ops >= best)
    return;
  if(pos == N) {
    best = ops;
    return;
  }
  if(A > m[pos])
    f(pos + 1, A + m[pos], ops);
  else {
    f(pos + 1, A, ops + 1); //skip
    f(pos , A + A - 1, ops + 1); //add
  }
}

int main() {
  int tc, cn, i;
  long long A;
  scanf("%d", &tc);
  for(cn = 1; cn <= tc; cn++) {
    scanf("%lld%d", &A, &N);
    best = INT_MAX;
    for(i = 0; i < N; i++)
      scanf("%lld", &m[i]);
    sort(m, m + N);
    f(0, A, 0);
    printf("Case #%d: %d\n", cn, best);
  }
  return 0;
}
