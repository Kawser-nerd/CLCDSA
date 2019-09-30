#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <complex>
#include <valarray>
#include <unordered_map>
#include <array>
#include <fstream>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <random>
#include <numeric>

#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define mod(n, m) (((n)%(m)+(m))%m)
#define fi first
#define sc second
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
const int INFINT = 1 << 30;                          // 1.07x10^ 9
const ll INFLL = 1LL << 60;                          // 1.15x10^18
const double EPS = 1e-10;
const int MOD = 1000000007;

int a, b, c, d, e, f;

int main() {
  cin >> a >> b >> c >> d >> e >> f;

  int water = 100*a, sugar = 0;
  for (int i = 0; i*100*a <= f; ++i) {
    for (int j = 0; j*100*b+i*100*a <= f; ++j) {
      if (i == 0 && j == 0) continue;
      int ub = min(f-100*(i*a+j*b), (i*a+j*b)*e);
      int tw = 100*(i*a+j*b), ts = 0;
      for (int k = 0; c*k <= ub; ++k) {
        for (int l = 0; c*k+d*l <= ub; ++l) {
          ts = max(ts, c*k+d*l);
        }
      }
      if ((tw+ts)*sugar < (water+sugar)*ts) {
        water = tw; sugar = ts;
      }
    }
  }

  printf("%d %d\n", water+sugar, sugar);

  return 0;
}