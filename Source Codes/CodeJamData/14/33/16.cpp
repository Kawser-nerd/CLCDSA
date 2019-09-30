#include <cstdio>
#include <cassert>

#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cerr << #x" = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int solve(int R, int C, int K) {
  if (C == 1) return K;

  int x = C / 2;
  int y = C - 1 - x;
  vector<int> v;
  v.push_back(x);
  v.push_back(x);
  v.push_back(y);
  v.push_back(y);

  for (;;) {
    sort(v.begin(), v.end());

    int border = 2*R + 2*C - 4;
    int enclosed = R*C;
    for (int x : v) {
      border -= x;
      enclosed -= x * (x+1) / 2;
    }
    if (enclosed >= K) return border;

    assert(v.back() > 0);
    --v.back();
  }

  assert(false);
  return -1;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int tt = 1; tt <= T; ++tt) {
    int R, C, K;
    scanf("%d%d%d", &R, &C, &K);

    if (R < C) swap(R, C);

    int ans = R*C;
    for (int r = 1; r <= R; ++r)
      for (int c = 1; c <= r && c <= C; ++c)
        if (r*c >= K)
          ans = min(ans, solve(r, c, K));

    printf("Case #%d: %d\n", tt, ans);
  }
  return 0;
}
