#include "climits"
#include "cmath"
#include "cstdio"
#include "algorithm"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "stack"
#include "string"
#include "utility"
#include "vector"
using namespace std;
typedef long long i64;

int nstate[1000];
i64 value[1000], vsum[1001];
int mark[1000];

int main() {
  int T; scanf("%d", &T);
  for (int Ti = 1; Ti <= T; ++Ti) {
    i64 r, c; int n; scanf("%lld %lld %d", &r, &c, &n);
    vector<i64> v(n);
    for (int i = 0; i < n; ++i) scanf("%lld", &v[i]);
    for (int i = 0; i < n; ++i) {
      nstate[i] = -1, value[i] = 0;
      for (int j = 0; j < n && nstate[i] == -1; ++j) {
        const int ns = (i + j) % n;
        if (value[i] + v[ns] > c) nstate[i] = ns;
        else value[i] += v[ns];
      }
      if (nstate[i] == -1) nstate[i] = i;
    }
    memset(mark, -1, sizeof(mark));
    vsum[0] = 0; int k = 0, st = 0;
    for (; mark[st] == -1; ++k, st = nstate[st])
      vsum[k + 1] = vsum[mark[st] = k] + value[st];
    i64 total = 0;
    if (r <= k) total += vsum[r];
    else {
      total += vsum[k], r -= k;
      const i64 cycle = vsum[k] - vsum[mark[st]];
      const int cycleLength = k - mark[st];
      total += cycle * (r / cycleLength);
      total += vsum[mark[st] + (int)(r % cycleLength)] - vsum[mark[st]];
    }
    printf("Case #%d: %lld\n", Ti, total);
  }
  return 0;
}
