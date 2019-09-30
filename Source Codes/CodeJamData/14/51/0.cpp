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

long long a[2000010];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int n, p, q, r, s;
    scanf("%d %d %d %d %d", &n, &p, &q, &r, &s);
    for (int i = 0; i < n; i++) {
      a[i] = ((i * 1LL * p + q) % r + s);
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i];
    }
    long long low = 0;
    long long high = sum;
    while (low < high) {
      long long mid = (low + high) >> 1;
      int pos = 0;
      for (int j = 0; j < 3; j++) {
        long long sum = 0;
        while (pos < n && sum + a[pos] <= mid) {
          sum += a[pos];
          pos++;
        }
      }
      if (pos == n) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    printf("%.17lf\n", 1.0 * (sum - low) / sum);
  }
  return 0;
}
