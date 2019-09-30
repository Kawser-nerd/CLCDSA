#define NDEBUG
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

template<typename T, typename U> inline void makemax(T &res, const U &x) {
  if (x > res) {
    res = x;
  }
}
#define MINUSONE(v) memset((v), -1, sizeof (v))

const int MAXN = 100;
const int MAXH = 200;
const int MINP = 20;
const int MAXSHOTS = MAXN * MAXH / MINP;

int P, Q, n, H[MAXN+1], G[MAXN];

int memo[MAXN][MAXH+1][MAXSHOTS+1][2];
int calc(int pos, int health, int buf, int turn) {
  if (pos == n) {
    return 0;
  }

  assert(health > 0);
  int &ret = memo[pos][health][buf][turn];
  if (ret != -1) {
    return ret;
  }

  ret = 0;
  if (turn == 0) {
    for (int i=0; i<=buf; ++i) {
      int hit = i * P;
      if (hit >= health) {
        makemax(ret, G[pos] + calc(pos+1, H[pos+1], buf-i, turn));
      } else {
        makemax(ret, calc(pos, health - hit, buf-i, !turn));
      }
    }
  } else {
    int hit = Q;
    if (hit >= health) {
      makemax(ret, calc(pos+1, H[pos+1], buf+1, !turn));
    } else {
      makemax(ret, calc(pos, health - hit, buf+1, !turn));
    }
  }
  return ret;
}

int solve() {
  cin >> P >> Q >> n;
  for (int i=0; i<n; ++i) {
    cin >> H[i] >> G[i];
  }

  for (int i=0; i<n; ++i) {
    MINUSONE(memo[i]);
  }
  return calc(0, H[0], 1, 0);
}

int main() {
  ios_base::sync_with_stdio(0);

  int T;
  cin >> T;
  for (int tt=1; tt<=T; ++tt) {
    printf("Case #%d: %d\n", tt, solve());
  }
}
