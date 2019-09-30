#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq=1;qq<=tt;qq++) {
    printf("Case #%d: ", qq);
    long long a[42], b;
    int n;
    cin >> b >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=n+1;i<=37;i++) a[i] = 0;
    sort(a+1, a+37+1);
    a[38] = (long long)1e16;
    long double ans = 0.0;
    for (int p=1;p<=37;p++) {
      for (int k=1;k<=p;k++) {
        long long lg = a[p];
        long long rg = a[p+1]-1;
        if (lg > rg) continue;
        long long loss = p-k;
        for (int i=1;i<=p;i++) loss -= a[i];
        long long rg2 = (b-loss)/p;
        if (rg2 < rg) rg = rg2;
        if (lg > rg) continue;
        long double c = -(p-k);
        for (int i=1;i<=k;i++) c -= 36.0/k*a[i];
        for (int i=1;i<=p;i++) c += a[i];
        if (p < 36) c += (36.0-p)*rg;
        else c += (36.0-p)*lg;
        if (c > ans) ans = c;
      }
    }
    printf("%.17lf\n", (double)ans);
  }
  return 0;
}
