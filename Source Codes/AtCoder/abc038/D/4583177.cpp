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
  if (a.second == b.second)
    return a.first > b.first;
  return a.second < b.second;
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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

ll N;
vector<ll> bit(100002, 0);
vector<ll> dp(100002, 0);

// a????w???????
void update(ll a, ll w) {
  for (ll x = a; x <= 100002; x += x & -x)
    bit[x] = max(bit[x], w);
}
ll get_min(ll a) {
  ll ret = 0;
  for (ll x = a; x > 0; x -= x & -x)
    ret = max(ret, bit[x]);
  return ret;
}
int main() {
  cin >> N;
  vector<Pair> A;
  REP(i, N) {
    ll w, h;
    cin >> w >> h;
    A.push_back(make_pair(w, h));
  }
  sort(ALL(A), pairCompare);
  REP(i, N) {
    dp[i] = get_min(A[i].first - 1) + 1;
    update(A[i].first, dp[i]);
  }
  cout << MAX(dp) << endl;
  // AUTO(a, A) { cout << a.first << "," << a.second << endl; }
  // REP(i, 15) { cout << i << "," << dp[i] << endl; }
  return 0;
}