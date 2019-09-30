#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;

#define all(c) ((c).begin()), ((c).end()) 
#define iter(c) __typeof((c).begin())
#define present(c, e) ((c).find((e)) != (c).end()) 
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

typedef long long ll;

int readint() { 
  int i, j, s;
  while (!isdigit(i = getchar()) && i != '-');
  if (i == '-') { s = -1; j = 0; }
  else { s = 1; j = i - '0'; }
  while (isdigit(i = getchar())) j = ((j << 1) + (j << 3) + (i - '0'));
  return j * s;
}

const ll INF = 987654321987654321LL;

int H, W;
int A[30][30], B[30][30], C[30][30];

ll pot[50][50];

ll hor(ll t, int A, int B, int C) {
  ll i = (t - (A + C)) / (A + B) - 10;
  for (;; i++) {
    ll a = C + (A + B) * i + A;
    ll b = C + (A + B) * i + A + B;
    if (a <= t && t < b) return t;
    else if (t < a) return a;
  }
}

ll ver(ll t, int A, int B, int C) {
  ll i = (t - C) / (A + B) - 10;
  for (;; i++) {
    ll a = C + (A + B) * i;
    ll b = C + (A + B) * i + A;
    if (a <= t && t < b) return t;
    else if (t < a) return a;
  }
}

bool in_range(int x, int y) {
  return 0 <= x && x < W * 2 && 0 <= y && y < H * 2;
}

int main() {
  int cases = readint();
  rep (ca, cases) {
    H = readint();
    W = readint();
    
    rep (y, H) rep (x, W) scanf("%d%d%d", &A[y][x], &B[y][x], &C[y][x]);

    rep (y, H * 2) rep (x, W * 2) pot[y][x] = INF;
    multimap<ll, pair<int, int > > que;
    pot[H * 2 - 1][0] = 0;
    que.insert(mp(0LL, mp(0, H * 2 - 1)));

    while (!que.empty()) {
      int x = que.begin()->second.first;
      int y = que.begin()->second.second;
      ll p = pot[y][x];
      que.erase(que.begin());

      // printf("%d %d: %lld\n", x, y, p);

      if (x == W * 2 - 1 && y == 0) {
        printf("Case #%d: %lld\n", ca + 1, p);
        break;
      }

      int cx = x / 2, cy = y / 2;
      
      // 横に移動
      for (int dx = -1; dx <= 1; dx += 2) {
        int tx = x + dx;
        int ty = y;
        if (!in_range(tx, ty)) continue;
        
        ll tp;
        if (x / 2 == tx / 2)
          tp = hor(p, A[cy][cx], B[cy][cx], C[cy][cx]) + 1;
        else
          tp = p + 2;
        
        // printf(" %d %d: %lld (%lld)\n", tx, ty, tp, pot[ty][tx]);
        if (tp < pot[ty][tx]) {
          pot[ty][tx] = tp;
          que.insert(mp(tp, mp(tx, ty)));
        }
      }
      for (int dy = -1; dy <= 1; dy += 2) {
        int tx = x;
        int ty = y + dy;
        if (!in_range(tx, ty)) continue;

        ll tp;
        if (y / 2 == ty / 2)
          tp = ver(p, A[cy][cx], B[cy][cx], C[cy][cx]) + 1;
        else
          tp = p + 2;

        // printf(" %d %d: %lld\n", tx, ty, tp);
        if (tp < pot[ty][tx]) {
          pot[ty][tx] = tp;
          que.insert(mp(tp, mp(tx, ty)));
        }
      }
    }
  }
}
