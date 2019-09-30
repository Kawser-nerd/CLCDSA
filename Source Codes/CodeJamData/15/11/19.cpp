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
int a[10005];

void solve() {
  int n;
  LL p=0, q=0, r=0;
  scanf("%d", &n);
  for(int i=0;i<n;i++) scanf("%d", &a[i]);
  for(int i=1;i<n;i++) {
    if (a[i] < a[i-1]) 
      p += a[i-1]-a[i];
    q = max(q, (LL)a[i-1]-a[i]);
  }
  for(int i=0;i<n-1;i++)
    r += min((LL)a[i], q);
  printf("Case #%d: %lld %lld\n", cs, p, r);
}

int main(void) {
  scanf("%d", &T);
  for(cs=1;cs<=T;cs++) solve();
  
  return 0;
}
