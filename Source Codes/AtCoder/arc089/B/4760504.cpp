#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
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

typedef pair<ll, ll> pll;
bool paircomp(const pll &a, const pll &b) {
  if (a.first == b.first)
    return a.second < b.second;
  return a.first < b.first;
}

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
#define REV(T) greater<T>()
#define PQ(T) priority_queue<T, vector<T>, greater<T>>
#define VVL(a, b, c) vector<vector<ll>>(a, vector<ll>(b, c))
#define VVVL(a, b, c, d)                                                       \
  vector<vector<vector<ll>>>(a, vector<vector<ll>>(b, vector<ll>(c, d)))
#define SP(a) setprecision(a)

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll N, K;
  cin >> N >> K;
  vvl F = VVL((2 * K) + 1, (2 * K) + 1, 0);
  vvl F2 = VVL((2 * K) + 1, (2 * K) + 1, 0);
  vvl SF = VVL((2 * K) + 2, (2 * K) + 2, 0);
  vvl SF2 = VVL((2 * K) + 2, (2 * K) + 2, 0);
  REP(i, N) {
    ll x, y;
    char c;
    cin >> x >> y >> c;
    if (c == 'B')
      F[((y + K) % (2 * K)) + 1][(x % (2 * K)) + 1] += 1;
    else
      F[(y % (2 * K)) + 1][(x % (2 * K)) + 1] += 1;
    if (c == 'B')
      F2[(y % (2 * K)) + 1][(x % (2 * K)) + 1] += 1;
    else
      F2[((y + K) % (2 * K)) + 1][(x % (2 * K)) + 1] += 1;
  }
  FOR(y, 1, (2 * K) + 1) FOR(x, 1, (2 * K) + 1) {
    SF[y][x] = F[y][x] + SF[y - 1][x] + SF[y][x - 1] - SF[y - 1][x - 1];
    SF2[y][x] = F2[y][x] + SF2[y - 1][x] + SF2[y][x - 1] - SF2[y - 1][x - 1];
  }

  ll ans = 0;
  REP(i, K + 1) REP(j, K + 1) {
    ll b1 = SF[i][j]; //??
    ll b2 = SF[i + K][j + K] - SF[i][j + K] - SF[i + K][j] + SF[i][j];
    ll b3 = SF[2 * K][2 * K] - SF[i + K][2 * K] - SF[2 * K][j + K] +
            SF[i + K][j + K];
    ll b4 = SF[2 * K][j] - SF[i + K][j];
    ll b5 = SF[i][2 * K] - SF[i][j + K];

    ans = max(ans, b1 + b2 + b3 + b4 + b5);
    // cout << ans << " " << i << "," << j << endl;
  }
  REP(i, K + 1) REP(j, K + 1) {
    ll b1 = SF2[i][j]; //??
    ll b2 = SF2[i + K][j + K] - SF2[i][j + K] - SF2[i + K][j] + SF2[i][j];
    ll b3 = SF2[2 * K][2 * K] - SF2[i + K][2 * K] - SF2[2 * K][j + K] +
            SF2[i + K][j + K];
    ll b4 = SF2[2 * K][j] - SF2[i + K][j];
    ll b5 = SF2[i][2 * K] - SF2[i][j + K];

    ans = max(ans, b1 + b2 + b3 + b4 + b5);
    // cout << ans << " " << i << "," << j << endl;
  }

  cout << ans << endl;

  return 0;
}