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
#define rrep(X,Y) for (int (X) = Y-1;(X) >= 0;--(X))
#define repa(X,A,Y) for (int (X) = A;(X) <= (Y);++(X))
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

const int MAX_N = 100000;
ll N, L, T;
ll X[MAX_N+1], W[MAX_N+1];

int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);
  
  cin >> N >> L >> T;
  repa(i, 1, N) cin >> X[i] >> W[i];

  vector<int> pos(N);
  for (int i = 1; i <= N; ++i) {
    if (W[i] == 1) {
      pos[i-1] = mod(X[i]+T, L);
    } else {
      pos[i-1] = mod(X[i]-T, L);
    }
  }
  ll pos0 = pos[0];
  sort(all(pos));

  ll id = 0;
  if (W[1] == 1) {
    for (int i = 2; i <= N; ++i) {
      if (W[i] == 2) {
        if (X[i]-X[1] > 2*T) continue;
        ll K = (2*T-X[i]+X[1])/L + 1;
        if ((2*T-X[i]+X[1])%L == 0) --K;
        id += K;
        id %= N;
      }
    }
    id = mod(id, N);
  } else {
    for (int i = 2; i <= N; ++i) {
      if (W[i] == 1) {
        if (L-X[i]+X[1] > 2*T) continue;
        ll K = (2*T-L+X[i]-X[1])/L + 1;
        id -= K;
        id %= N;
      }
    }
    id = mod(id, N);
  }

  vector<Pii> ans;
  int i = lower_bound(all(pos), pos0) - pos.begin();
  for (int k = 0; k < N; ++k) {
    ans.push_back(Pii(mod(id-i+k, N), pos[k]));
  }
  sort(all(ans));

  for (int i = 0; i < N; ++i) {
    cout << ans[i].sc << endl;
  }

  return 0;
}