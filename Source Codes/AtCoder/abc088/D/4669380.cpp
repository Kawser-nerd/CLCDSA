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
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vvvl = vector<vector<vector<ll>>>;
using edge = struct {
  int to;
  int cost;
};
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define RREP(i, n) for (ll i = (n)-1; i >= 0; i--)
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
#define PQ(T) priority_queue<T, vector<T>, greater<T>>
#define VVL(a, b, c) vector<vector<ll>>(a, vector<ll>(b, c))
#define VVVL(a, b, c, d)                                                       \
  vector<vector<vector<ll>>>(a, vector<vector<ll>>(b, vector<ll>(c, d)))

typedef pair<ll, ll> pll;
bool paircomp(const pll &a, const pll &b) {
  if (a.first == b.first)
    return a.second < b.second;
  return a.first < b.first;
}

ll POW(ll n, ll m) {
  if (m == 0) {
    return 1;
  } else if (m % 2 == 0) {
    ll tmp = POW(n, m / 2);
    return (tmp * tmp);
  } else {
    return (n * POW(n, m - 1));
  }
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

ll P[52][52] = {};
string A[52];
ll H, W;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  REP(i, 50) REP(j, 50) P[i][j] = llINF;
  cin >> H >> W;
  REP(i, H) cin >> A[i];
  ll ans = 0;
  REP(i, H) REP(j, W) {
    if (A[i][j] == '.')
      ans++;
  }

  queue<pll> que;
  que.push(make_pair(0, 0));
  P[0][0] = 1;
  while (!que.empty()) {
    auto pos = que.front();
    que.pop();
    ll x = pos.first;
    ll y = pos.second;
    // cout << x << "," << y << endl;
    if (x == W - 1 && y == H - 1) {
      break;
    }
    REP(i, 4) {
      if (x + dx[i] < W && x + dx[i] > -1 && y + dy[i] < H && y + dy[i] > -1 &&
          A[y + dy[i]][x + dx[i]] == '.' && P[y + dy[i]][x + dx[i]] == llINF) {
        P[y + dy[i]][x + dx[i]] = P[y][x] + 1;
        que.push(make_pair(x + dx[i], y + dy[i]));
      }
    }
  }

  if (P[H - 1][W - 1] == llINF)
    cout << -1 << endl;
  else
    cout << ans - P[H - 1][W - 1] << endl;

  return 0;
}