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

const int inf = (int)1e9;
const int N = 4010;

char s[N][N];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    fflush(stdout);
    int n;
    scanf("%d", &n);
    n *= 2;
    for (int i = 0; i < n; i++) {
      scanf("%s", s[i]);
    }
    int ans = 0;
    for (int rot = 0; rot < 2; rot++) {
      bool ok = true;
      int w[4];
      w[0] = w[1] = w[2] = w[3] = 0;
      for (int i = 0; i < n; i++) {
        int eq = 0, neq = 0;
        for (int j = 0; j < n; j++) {
          if (s[i][j] == s[0][j]) {
            eq++;
          } else {
            neq++;
          }
        }
        if (eq > 0 && neq > 0) {
          ok = false;
          break;
        }
        w[(eq == n ? 0 : 2) + (i & 1)]++;
      }
      if (!ok || w[0] + w[1] != n / 2) {
        ans = inf;
        break;
      }
      if (w[0] < w[1]) {
        ans += w[0];
      } else {
        ans += w[1];
      }
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          swap(s[i][j], s[j][i]);
        }
      }
    }
    if (ans == inf) {
      printf("IMPOSSIBLE\n");
    } else {
      printf("%d\n", ans);
    }
    fflush(stdout);
  }
  return 0;
}
