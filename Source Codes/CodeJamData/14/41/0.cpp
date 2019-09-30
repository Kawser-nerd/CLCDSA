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

int a[1234567];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq=1;qq<=tt;qq++) {
    printf("Case #%d: ", qq);
    int n, x;
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    sort(a, a + n);
    int j = n - 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      while (j > i && a[i] + a[j] > x) j--;
      if (j <= i) break;
      ans++;
      j--;
    }
    printf("%d\n", n - ans);
  }
  return 0;
}
