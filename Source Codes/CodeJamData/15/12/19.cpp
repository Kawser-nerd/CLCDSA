#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
using namespace std;
typedef long long LL;

int T, cs;
LL a[1005];

void solve() {
  int B;
  LL N;
  printf("Case #%d: ", cs);
  scanf("%d%lld", &B, &N);
  for(int i=0;i<B;i++) scanf("%lld", &a[i]);
  for(int i=0;i<B;i++) {
    LL l = 0, r = N * a[i], m, cnt;
    while (l <= r) {
      m = (l+r)/2;
      cnt = 0;
      for(int j=0;j<i;j++) cnt += (m + a[j]) / a[j];
      for(int j=i;j<B;j++) cnt += (m + a[j]-1) / a[j];
      if (cnt == N-1 && m%a[i]==0) {
        printf("%d\n", i+1);
        return;
      }
      if (cnt >= N) { r = m-1; }
      else { l = m+1; }
    }
  }
  fprintf(stderr, "ERR!\n");
  return;
}
int main(void) {
  scanf("%d", &T);
  for(cs=1;cs<=T;cs++) solve();
  return 0;
}
