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
bool pairCompare(const Pair &firstElof, const Pair &secondElof) {
  return firstElof.second > secondElof.second;
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

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N, 0);
  REP(i, N) cin >> A[i];

  ll left = 1;
  ll right = N;
  bool end = true;
  ll LAST = 0;
  AUTO(a, A) {
    if (LAST >= a)
      end = false;
    LAST = a;
  }
  if (end) {
    cout << 1 << endl;
    return 0;
  }

  while (right - left > 1) {
    ll mid = left + (right - left) / 2;
    ll LAST = 0;
    vector<Pair>
        X; //????????(0)?????????{????????,?????}
    AUTO(a, A) {
      if (LAST >= a) {
        while (!X.empty() && X.back().first > a)
          X.pop_back();
        X.push_back(make_pair(a + 1, mid));
      }
      LAST = a;
      while (!X.empty() && X.back().second == mid) {
        ll po = X.back().first;
        X.pop_back();
        if (!X.empty() && X.back().first == po - 1) {
          ll yo = X.back().second;
          X.pop_back();
          X.push_back(make_pair(po - 1, yo + 1));
        } else {
          X.push_back(make_pair(po - 1, 1));
        }
      }
    }

    // ?????0???????????????
    if (X.front().first > 0)
      right = mid;
    else
      left = mid;
  }
  cout << right << endl;

  return 0;
}