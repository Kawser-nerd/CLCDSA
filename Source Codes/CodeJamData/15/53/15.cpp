#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <array>
#include <list>
#include <stack>
#include <valarray>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef unsigned long long UInt;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }
double fin() { double x; scanf("%lf", &x); return x; }
Int lin() { Int x; scanf("%lld", &x); return x; }

struct quail {
  Int pos, speed;
} Q[512], LS[512], RS[512];

double dp[512][512][2];

void solve() {
  Int Y = in();
  int N = in();
  for (int i = 0; i < N; ++i) {
    Q[i].pos = in();
  }
  for (int i = 0; i < N; ++i) {
    Q[i].speed = in();
  }
  sort(Q, Q + N, [] (const quail& a, const quail& b) {
    return a.pos < b.pos;
  });

  int L = 0;
  for (int i = 0; i < N; ++i) {
    if (Q[i].pos > 0) {
      L = i;
      break;
    }
  }

  if (L == 0) {
    double res = 0.0;
    for (int i = 0; i < N; ++i) {
      chmax(res, fabs(Q[i].pos) / (double)(Y - Q[i].speed));
    }
    printf("%.9f\n", res);
    return;
  }

  for (int i = L - 1; i >= 0; --i) {
    LS[i] = Q[i];
    LS[i].pos = fabs(LS[i].pos);
  }
  sort(LS, LS + L, [] (const quail& a, const quail& b) {
    return a.pos != b.pos ? a.pos < b.pos : a.speed < b.speed;
  });
  int R = N - L;
  for (int i = L; i < N; ++i) {
    RS[i - L] = Q[i];
  }
  sort(RS, RS + R, [] (const quail& a, const quail& b) {
    return a.pos != b.pos ? a.pos < b.pos : a.speed < b.speed;
  });

  for (int i = 0; i < L; ++i) {
    bool fast = true;
    for (int j = i + 1; j < L; ++j) {
      fast &= LS[i].speed > LS[j].speed;
    }
    if (!fast) {
      for (int j = i; j < L - 1; ++j) {
        LS[j] = LS[j + 1];
      }
      --L;
    }
  }
  for (int i = 0; i < R; ++i) {
    bool fast = true;
    for (int j = i + 1; j < R; ++j) {
      fast &= RS[i].speed > RS[j].speed;
    }
    if (!fast) {
      for (int j = i; j < R - 1; ++j) {
        RS[j] = RS[j + 1];
      }
      --R;
    }
  }

  for (int i = 0; i <= L; ++i) {
    for (int j = 0; j <= R; ++j) {
      dp[i][j][0] = dp[i][j][1] = 1e15;
    }
  }

  dp[1][0][0] = LS[0].pos / (double)(Y - LS[0].speed);
  dp[0][1][1] = RS[0].pos / (double)(Y - RS[0].speed);

  double res = 1e15;
  for (int i = 0; i <= L; ++i) {
    for (int j = 0; j <= R; ++j) {
      if (dp[i][j][0] < 1e15) {
        bool done = true;
        const double t = dp[i][j][0];
        const double curpos = LS[i - 1].pos + LS[i - 1].speed * t;
        if (i < L) {
          int ii = i;
          while (ii < L) {
            if (curpos < LS[ii].pos + LS[ii].speed * t) {
              break;
            }
            ++ii;
          }
          if (ii < L) {
            done = false;
            chmin(dp[ii + 1][j][0], t + (LS[ii].pos + LS[ii].speed * t - curpos) / (Y - LS[ii].speed));
          }
        }
        if (j < R) {
          int jj;
          if (j == 0) {
            jj = 0;
          } else {
            const double tt = t - (RS[j - 1].pos + RS[j - 1].speed * t + curpos) / (Y + RS[j - 1].speed);
            const double curpos2 = RS[j - 1].pos + RS[j - 1].speed * tt;
            jj = j;
            while (jj < R) {
              if (curpos2 < RS[jj].pos + RS[jj].speed * tt) {
                break;
              }
              ++jj;
            }
          }
          if (jj < R) {
            done = false;
            chmin(dp[i][jj + 1][1], t + (RS[jj].pos + RS[jj].speed * t + curpos) / (Y - RS[jj].speed));
          }
        }
        if (done) {
          // cerr<<'L'<<i<<' '<<j<<' '<<t<<endl;
          chmin(res, t);
        }
      }

      if (dp[i][j][1] < 1e15) {
        bool done = true;
        const double t = dp[i][j][1];
        const double curpos = RS[j - 1].pos + RS[j - 1].speed * t;
        if (j < R) {
          int jj = j;
          while (jj < R) {
            if (curpos < RS[jj].pos + RS[jj].speed * t) {
              break;
            }
            ++jj;
          }
          if (jj < R) {
            done = false;
            chmin(dp[i][jj + 1][1], t + (RS[jj].pos + RS[jj].speed * t - curpos) / (Y - RS[jj].speed));
          }
        }
        if (i < L) {
          int ii;
          if (i == 0) {
            ii = 0;
          } else {
            const double tt = t - (LS[i - 1].pos + LS[i - 1].speed * t + curpos) / (Y + LS[i - 1].speed);
            // if(i==2&&j==2)cerr<<t<<' '<<tt<<endl;
            const double curpos2 = LS[i - 1].pos + LS[i - 1].speed * tt;
            ii = i;
            while (ii < L) {
              if (curpos2 < LS[ii].pos + LS[ii].speed * tt) {
                break;
              }
              ++ii;
            }
          }
          if (ii < L) {
            done = false;
            chmin(dp[ii + 1][j][0], t + (LS[ii].pos + LS[ii].speed * t + curpos) / (Y - LS[ii].speed));
          }
        }
        if (done) {
          // cerr<<'R'<<i<<' '<<j<<' '<<t<<endl;
          chmin(res, t);
        }
      }
    }
  }

  printf("%.9f\n", res);
}

int main() {
  int T = in();

  for (int CN = 1; CN <= T; ++CN) {
    printf("Case #%d: ", CN);
    solve();
  }

  return 0;
}
