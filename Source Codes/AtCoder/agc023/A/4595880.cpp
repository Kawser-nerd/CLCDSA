#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

const int MOD = 1e9 + 7;
const int iINF = 1000000000;
const long long int llINF = 1000000000000000000;

using namespace std;
using ll = long long int;
using vv = vector<vector<ll>>;
using vvv = vector<vector<vector<ll>>>;
using edge = struct {
  int to;
  int cost;
};
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define AUTO(i, m) for (auto &i : m)
#define ALL(a) (a).begin(), (a).end()
#define MAX(vec) *std::max_element(vec.begin(), vec.end())
#define MIN(vec) *std::min_element(vec.begin(), vec.end())
#define ARGMAX(vec)                                                            \
  std::distance(vec.begin(), std::max_element(vec.begin(), vec.end()))
#define ARGMIN(vec)                                                            \
  std::distance(vec.begin(), std::min_element(vec.begin(), vec.end()))
#define BIT(n, num) std::bitset<(n)>((num)).to_string()
#define REV(T) greater<T>()
#define PQ priority_queue<ll, vector<ll>, greater<ll>>
#define VVI(a, b, c) vector<vector<ll>>(a, vector<ll>(b, c))
#define VVVI(a, b, c, d)                                                       \
  vector<vector<vector<ll>>>(a, vector<vector<ll>>(b, vector<ll>(c, d)))

typedef pair<ll, ll> Pair;
bool pairCompare(const Pair &a, const Pair &b) {
  if (a.first == b.first)
    return a.second < b.second;
  return a.first < b.first;
}

ll POW(ll n, ll m) {
  if (m == 0) {
    return 1;
  } else if (m % 2 == 0) {
    ll tmp = POW(n, m / 2);
    return (tmp * tmp) % MOD;
  } else {
    return (n * POW(n, m - 1)) % MOD;
  }
}
ll factorial(ll n) {
  ll ans = 1;
  for (ll i = 2; i <= n; i++) {
    ans *= i;
    ans %= MOD;
  }
  return ans;
}
ll P(ll n, ll m) {
  ll ans = 1;
  for (ll i = m + 1; i <= n; i++) {
    ans *= i;
    ans %= MOD;
  }
  return ans;
}

ll C(ll n, ll m) { return (P(n, n - m) * POW(factorial(m), MOD - 2)) % MOD; }

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ll N;
  cin >> N;
  map<ll, ll> M;
  vector<ll> A(N, 0);
  ll S = 0;
  REP(i, N) cin >> A[i];
  REP(i, N) {
    S = S + A[i];
    if (M.find(S) != M.end())
      M[S] = M[S] + 1;
    else
      M[S] = 1;
  }
  ll ans = 0;
  AUTO(m, M) {
    if (m.first == 0) {
      ans += (m.second + 1) * m.second / 2;
    } else if (m.second >= 2) {
      ans += m.second * (m.second - 1) / 2;
    }
  }
  cout << ans << endl;
  return 0;
}