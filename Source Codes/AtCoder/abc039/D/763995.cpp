#include <stdint.h>
#include <array>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstdio>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-12;
static const double PI = acos(-1.0);
static const ll MOD = 1000000007;

#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(a) (a).begin(), (a).end()
#define DEBUG(x) cout << #x << ": " << x << endl

int main() {
  int H;
  int W;
  cin >> H >> W;
  vector<string> S(H);
  REP(i, H) cin >> S[i];
  vector<string> org = S;
  REP(y, H) {
    REP(x, W) {
      for (int j = -1; j <= 1; j++) {
        for (int i = -1; i <= 1; i++) {
          int xx = x + i;
          int yy = y + j;
          if (0 <= xx && xx < W &&
              0 <= yy && yy < H &&
              S[yy][xx] == '.') {
            org[y][x] = '.';
          }
        }
      }
    }
  }
  vector<string> T = org;
  REP(y, H) {
    REP(x, W) {
      for (int j = -1; j <= 1; j++) {
        for (int i = -1; i <= 1; i++) {
          int xx = x + i;
          int yy = y + j;
          if (0 <= xx && xx < W &&
              0 <= yy && yy < H &&
              org[yy][xx] == '#') {
            T[y][x] = '#';
          }
        }
      }
    }
  }
  if (T == S) {
    std::cout << "possible" << std::endl;
    REP(i, H) std::cout << org[i] << std::endl;
  } else {
    std::cout << "impossible" << std::endl;
  }
}