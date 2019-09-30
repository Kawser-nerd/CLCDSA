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

const int N = 100010;

int dist[N];
bool b[N];
int c1[N], r1[N], c2[N], r2[N];

int get_one(int r, int c, int k) {
  int dx = 0;
  if (r < r1[k]) dx += r1[k] - r - 1;
  if (r > r2[k]) dx += r - r2[k] - 1;
  int dy = 0;
  if (c < c1[k]) dy += c1[k] - c - 1;
  if (c > c2[k]) dy += c - c2[k] - 1;
  return max(dx, dy);
}

int get_dist(int i, int j) {
  int a[8];
  a[0] = get_one(r1[i], c1[i], j);
  a[1] = get_one(r2[i], c1[i], j);
  a[2] = get_one(r1[i], c2[i], j);
  a[3] = get_one(r2[i], c2[i], j);
  a[4] = get_one(r1[j], c1[j], i);
  a[5] = get_one(r2[j], c1[j], i);
  a[6] = get_one(r1[j], c2[j], i);
  a[7] = get_one(r2[j], c2[j], i);
  int mn = a[0];
  for (int i = 1; i < 8; i++)
    if (a[i] < mn) mn = a[i];
  return mn;
}

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq=1;qq<=tt;qq++) {
    printf("Case #%d: ", qq);
    int w, h, bb;
    scanf("%d %d %d", &w, &h, &bb);
    for (int i = 0; i < bb; i++) {
      scanf("%d %d %d %d", c1 + i, r1 + i, c2 + i, r2 + i);
    }
    for (int i = 0; i < bb; i++) {
      dist[i] = c1[i];
      b[i] = true;
    }
    for (int it = 0; it < bb; it++) {
      int km = -1;
      for (int i = 0; i < bb; i++)
        if (b[i] && (km == -1 || dist[i] < dist[km])) km = i;
      b[km] = false;
      for (int j = 0; j < bb; j++) {
        int dd = dist[km] + get_dist(km, j);
        if (dd < dist[j]) {
          dist[j] = dd;
        }
      }
    }
    int ans = w;
    for (int i = 0; i < bb; i++) {
      int dd = dist[i] + (w - c2[i] - 1);
      if (dd < ans) ans = dd;
    }
    printf("%d\n", ans);
  }
  return 0;
}
