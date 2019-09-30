#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

bool b[12345];
int a[12345];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq=1;qq<=tt;qq++) {
    printf("Case #%d: ", qq);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      b[i] = true;
    }
    int ans = 0;
    for (int it = 1; it <= n; it++) {
      int mn = (int)2e9, km = -1;
      for (int i = 1; i <= n; i++)
        if (b[i]) {
          if (a[i] < mn) {
            mn = a[i];
            km = i;
          }
        }
      b[km] = false;
      int ll = 0, rr = 0;
      for (int j = 1; j <= n; j++)
        if (b[j]) {
          if (j < km) ll++;
          else rr++;
        }
      if (ll < rr) ans += ll;
      else ans += rr;
    }
    printf("%d\n", ans);
  }
  return 0;
}
