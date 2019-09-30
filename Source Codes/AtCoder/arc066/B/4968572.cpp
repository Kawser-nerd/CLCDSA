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
#define SQRT(a) sqrt((long double)(a))
#define DPOW(a, b) pow((long double)(a), (long double)(b))

ll POW(ll n, ll m) {
  if (m == 0) {
    return 1;
  } else if (m % 2 == 0) {
    ll tmp = POW(n, m / 2) % MOD;
    return (tmp * tmp);
  } else {
    return (n * POW(n, m - 1)) % MOD;
  }
}

ll MUL(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }

ll DIV(ll a, ll b) { return MUL(a, POW(b, MOD - 2)); }

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll N;
  cin >> N;
  vvl DP = VVL(61, 3, 0);
  bitset<60> bs(N);
  DP[60][0] = 1;
  RREP(i, 60) {
    if (bs[i] == 1) {
      //+1
      DP[i][0] = DP[i + 1][0];
      //+0 +2
      DP[i][1] = DP[i + 1][0] + DP[i + 1][1];
      // +0,+1 +0,+1,+2
      DP[i][2] = 2 * DP[i + 1][1] + 3 * DP[i + 1][2];
    } else {
      //+0 +2
      DP[i][0] = DP[i + 1][0] + DP[i + 1][1];
      //+1
      DP[i][1] = DP[i + 1][1];
      // +0 +0,+1,+2
      DP[i][2] = DP[i + 1][1] + 3 * DP[i + 1][2];
    }
    DP[i][0] %= MOD;
    DP[i][1] %= MOD;
    DP[i][2] %= MOD;
  }

  cout << ((DP[0][0] + DP[0][1]) % MOD + DP[0][2]) % MOD << endl;
  return 0;
}