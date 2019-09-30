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
    return (tmp * tmp) % MOD;
  } else {
    return (n * POW(n, m - 1)) % MOD;
  }
}

int dx[4] = {1, 0, -1};
int dy[4] = {1, 0, -1};

int main() {
  ll H, W;
  cin >> H >> W;
  vvl F = VVL(H + 3, W + 3, 1);
  vvl A = VVL(H + 3, W + 3, 0);

  FOR(h, 1, H + 1) {
    string inp = "";
    cin >> inp;
    REP(w, W) {
      if (inp[w] == '.')
        F[h][w + 1] = 0;
    }
  }
  bool ok = true;
  //???????
  FOR(h, 1, H + 1) {
    FOR(w, 1, W + 1) {
      ll count = 0;
      REP(i, 3) REP(j, 3) { count += F[h + dy[i]][w + dx[j]]; }
      if (count == 9)
        A[h][w] = 1;
    }
  }

  //??????????
  FOR(h, 1, H + 1) {
    if (!ok)
      break;
    FOR(w, 1, W + 1) {
      ll count = 0;
      REP(i, 3) REP(j, 3) { count += A[h + dy[i]][w + dx[j]]; }
      if ((count > 0 && F[h][w] == 1) || (count == 0 && F[h][w] == 0))
        continue;
      else {
        ok = false;
        break;
      }
    }
  }

  if (!ok)
    cout << "impossible" << endl;
  else {
    cout << "possible" << endl;
    FOR(h, 1, H + 1) {
      FOR(w, 1, W + 1) { cout << (A[h][w] == 0 ? '.' : '#'); }
      cout << endl;
    }
  }
  return 0;
}