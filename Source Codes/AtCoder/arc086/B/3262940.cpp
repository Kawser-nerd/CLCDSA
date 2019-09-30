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

#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
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

const int MAX_N = 50;
int N;
int a[MAX_N+1];

int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; ++i) cin >> a[i];

  int ma = -INFINT, mi = INFINT, ma_idx = 0, mi_idx= 0;
  for (int i = 1; i <= N; ++i) {
    if (ma < a[i]) {
      ma = a[i]; ma_idx = i;
    }
    if (mi > a[i]) {
      mi = a[i]; mi_idx = i;
    }
  }

  vector<Pii> ans;
  if (abs(ma) >= abs(mi)) {
    for (int i = 1; i <= N; ++i) {
      if (i == ma_idx) continue;
      ans.push_back(Pii(ma_idx, i));
    }
    for (int i = 1 ; i < N; ++i) {
      ans.push_back(Pii(i, i+1));
    }
  } else {
    for (int i = 1; i <= N; ++i) {
      if (i == mi_idx) continue;
      ans.push_back(Pii(mi_idx, i));
    }
    for (int i = N; i > 1; --i) {
      ans.push_back(Pii(i, i-1));
    }
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i].fi << ' ' << ans[i].sc << endl;
  }

  return 0;
}