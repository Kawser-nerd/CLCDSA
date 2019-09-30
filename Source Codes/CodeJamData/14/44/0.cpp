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

const int md = 1000000007;

const int N = 1234567;
const int CN = 2222;

int a[N][42];
bool fin[N];
int pv[N], sz[N];

char foo[N];

int c[CN][CN];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  memset(c, 0, sizeof(c));
  for (int i = 0; i < CN; i++)
    for (int j = 0; j < CN; j++)
      if (j == 0) c[i][j] = 1; else
      if (i == 0) c[i][j] = 0;
      else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % md;
  int tt;
  scanf("%d", &tt);
  for (int qq=1;qq<=tt;qq++) {
    printf("Case #%d: ", qq);
    int m, p;
    scanf("%d %d", &m, &p);
    int n = 1;
    fin[1] = false;
    for (int j = 0; j < 26; j++) a[1][j] = 0;
    for (int i = 0; i < m; i++) {
      scanf("%s", foo);
      int t = 1;
      for (int j = 0; foo[j]; j++) {
        int c = foo[j] - 'A';
        if (a[t][c] == 0) {
          n++;
          a[t][c] = n;
          fin[n] = false;
          pv[n] = t;
          for (int u = 0; u < 26; u++) a[n][u] = 0;
        }
        t = a[t][c];
      }
      fin[t] = true;
    }
    for (int i = 1; i <= n; i++) sz[i] = fin[i];
    for (int i = n; i >= 2; i--) sz[pv[i]] += sz[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      sz[i] = min(p, sz[i]);
      ans += sz[i];
    }
    int ways = 1;
    for (int i = 1; i <= n; i++) {
      vector <int> ch;
      int lg = 1;
      for (int j = 0; j < 26; j++)
        if (a[i][j] != 0) {
          int u = a[i][j];
          ch.push_back(sz[u]);
          if (sz[u] > lg) lg = sz[u];
        }
      if (fin[i]) {
        ch.push_back(1);
      }
      int nc = ch.size();
      int total = 0;
      for (int z = lg; z <= sz[i]; z++) {
        int cur = 1;
        for (int j = 0; j < nc; j++) {
          int u = ch[j];
          cur = (long long)cur * c[z][u] % md;
        }
        int mul = c[sz[i]][z];
        if ((z & 1) != (sz[i] & 1)) mul = md - mul;
        total = (total + (long long)cur * mul) % md;
      }
      ways = (long long)ways * total % md;
    }
    printf("%d %d\n", ans, ways);
    fflush(stdout);
  }
  return 0;
}
