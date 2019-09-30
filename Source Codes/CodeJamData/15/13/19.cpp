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
int n;
const int N = 6005;
LL a[N], b[N];
LL x[N], y[N]; int m;
int srt[N];

bool cmp(int i, int j) {
  //I or II
  bool f1 = (y[i]>0 || (y[i]==0 && x[i]>0));
  bool f2 = (y[j]>0 || (y[j]==0 && x[j]>0));
  if(f1 != f2) return f1;
  return (y[j] * x[i] - y[i] * x[j] > 0);
}

void solve() {
  scanf("%d", &n);
  printf("Case #%d:\n", cs);
  fprintf(stderr, "Case #%d:\n", cs);
  for(int i=0;i<n;i++) scanf("%lld%lld", &a[i], &b[i]);
  for(int i=0;i<n;i++) {
    m = 0;
    for(int j=0;j<n;j++) {
      if(i == j) continue;
      x[m] = a[j] - a[i];
      y[m] = b[j] - b[i];
      srt[m] = m;
      m++;
    }
    sort(srt, srt+m, cmp);
    int ans=n-1;
    for(int i=0;i<m;i++) srt[m+i] = srt[i];
    for(int p=0,q=0;p<m;p++) {
      while(q<p+m && y[srt[p]]*x[srt[q]]-y[srt[q]]*x[srt[p]]<=0) ++q;
      ans=min(ans, (n-1)-(q-p));
    }
    printf("%d\n", ans);
    fprintf(stderr, "%d\n", ans);
  }
}

int main(void) {
  scanf("%d", &T);
  for(cs=1;cs<=T;cs++) solve();
  return 0;
}
