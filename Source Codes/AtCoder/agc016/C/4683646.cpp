#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <utility>
#include <vector>
#include <complex>
#include <valarray>
#include <fstream>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <random>

#define _overload(a, b, c, d, ...) d
#define _rep1(X, A, Y) for (int (X) = (A);(X) <= (Y);++(X))
#define _rep2(X, Y) for (int (X) = 0;(X) < (Y);++(X))
#define rep(...) _overload(__VA_ARGS__, _rep1, _rep2)(__VA_ARGS__)
#define rrep(X,Y) for (int (X) = Y-1;(X) >= 0;--(X))
#define all(X) (X).begin(),(X).end()
#define _size(X) (int)((X).size())
#define mod(n, m) (((n)%(m)+(m))%m)
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
const int INFINT = 1 << 30;                          // 1.07x10^ 9
const ll INFLL = 1LL << 60;                          // 1.15x10^18
const double EPS = 1e-10;
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_H = 500, MAX_W = 500;
ll H, W, h, w;
ll ans[MAX_H][MAX_W];
ll INF = 1e9;

int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);
  
  cin >> H >> W >> h >> w;

  if (h == 1 && w == 1) {
      cout << "No" << endl;
      return 0;
  }

  ll ma = (INF-1)/(w*h-1);
  ll s = ma*(h*w-1) + 1;

  for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
          if ((i+1)%h == 0 && (j+1)%w == 0) {
              ans[i][j] = -s;
          } else {
              ans[i][j] = ma;
          }
      }
  }

  ll sum = 0;
  for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
          sum += ans[i][j];
      }
  }

  if (sum < 0) {
      cout << "No" << endl;
  } else {
      cout << "Yes" << endl;
      for (int i = 0; i < H; ++i) {
          for (int j = 0; j < W; ++j) {
              cout << ans[i][j];
              if (j+1 != W) cout << ' ';
              else cout << endl;
          }
      }
  }
}