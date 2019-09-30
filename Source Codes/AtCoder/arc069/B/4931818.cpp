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
  ll N;
  string S;
  cin >> N;
  cin >> S;

  // SS,SW,WW,WS
  vvl PO = VVL(4, N, 0);
  PO[1][1] = 1;
  PO[2][0] = 1, PO[2][1] = 1;
  PO[3][0] = 1;
  FOR(i, 1, N - 1) {
    if (S[i] == 'o') {
      REP(j, 4) {
        if (PO[j][i] == 0)
          PO[j][i + 1] = PO[j][i - 1];
        else
          PO[j][i + 1] = (PO[j][i - 1] + 1) % 2;
      }
    } else {
      REP(j, 4) {
        if (PO[j][i] == 0)
          PO[j][i + 1] = (PO[j][i - 1] + 1) % 2;
        else
          PO[j][i + 1] = PO[j][i - 1];
      }
    }
  }
  bool anyok = false;
  REP(i, 4) {
    bool ok = true;
    if (S[N - 1] == 'o' && PO[i][N - 1] == 0 && PO[i][N - 2] != PO[i][0])
      ok = false;
    if (S[N - 1] == 'x' && PO[i][N - 1] == 0 && PO[i][N - 2] == PO[i][0])
      ok = false;
    if (S[N - 1] == 'o' && PO[i][N - 1] == 1 && PO[i][N - 2] == PO[i][0])
      ok = false;
    if (S[N - 1] == 'x' && PO[i][N - 1] == 1 && PO[i][N - 2] != PO[i][0])
      ok = false;

    if (S[0] == 'o' && PO[i][0] == 0 && PO[i][N - 1] != PO[i][1])
      ok = false;
    if (S[0] == 'x' && PO[i][0] == 0 && PO[i][N - 1] == PO[i][1])
      ok = false;
    if (S[0] == 'o' && PO[i][0] == 1 && PO[i][N - 1] == PO[i][1])
      ok = false;
    if (S[0] == 'x' && PO[i][0] == 1 && PO[i][N - 1] != PO[i][1])
      ok = false;
    if (ok) {
      REP(j, N) cout << ((PO[i][j] == 0) ? 'S' : 'W');
      cout << endl;
      anyok = true;
      break;
    }
  }
  if (!anyok)
    cout << -1 << endl;

  return 0;
}