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
  string S = "";
  ll x = 0, y = 0;
  // ???????????
  vl DPX(16002, 0);
  vl DPY(16002, 0);
  ll state = 0; // 0:???1:y???2:x??
  DPX[8000] = 1;
  DPY[8000] = 1;
  cin >> S;
  cin >> x;
  cin >> y;
  ll i = 0;
  while (i < S.size()) {
    vl CPX = DPX;
    vl CPY = DPY;
    REP(j, 16000) {
      DPX[j] = 0;
      DPY[j] = 0;
    }
    if (S[i] == 'T') {
      if (state == 0)
        state = 1;
      else if (state == 1)
        state = 2;
      else
        state = 1;
      DPX = CPX;
      DPY = CPY;
      // REP(i, 16000) if (DPX[i] == 1) cout << i << endl;
    } else if (S[i] == 'F') {
      if (state == 0) {
        ll count = 1;
        while (i < S.size() - 1 && S[i + 1] == 'F') {
          count++;
          i++;
        }
        DPX[8000 + count] = 1;
        DPY[8000] = 1;
      }

      else if (state == 1) {
        ll count = 1;
        while (i < S.size() - 1 && S[i + 1] == 'F') {
          count++;
          i++;
        }
        REP(j, 16000) {
          if (CPY[j] == 1) {
            // cout << i << "," << j << endl;
            DPY[j + count] = 1;
            DPY[j - count] = 1;
          }
        }
        DPX = CPX;
      } else {
        ll count = 1;
        while (i < S.size() - 1 && S[i + 1] == 'F') {
          count++;
          i++;
        }
        REP(j, 16000) {
          if (CPX[j] == 1) {
            DPX[j + count] = 1;
            DPX[j - count] = 1;
          }
        }
        DPY = CPY;
      }
    }
    i++;
  }
  // REP(p, 16000) if (DPX[p] == 1) cout << p << endl;
  if (DPX[8000 + x] == 1 && DPY[8000 + y] == 1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}