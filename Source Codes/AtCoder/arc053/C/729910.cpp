#include <stdint.h>
#include <array>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstdio>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-12;
static const double PI = acos(-1.0);
static const ll MOD = 1000000007;

#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(a) (a).begin(), (a).end()
#define DEBUG(x) cout << #x << ": " << x << endl

int main() {
  int N;
  scanf("%d", &N);
  vector<pair<ll, ll>> m;
  vector<pair<ll, ll>> p;
  REP(i, N) {
    ll a;
    ll b;
    scanf("%lld %lld", &a, &b);
    if (a < b) {
      m.emplace_back(a, b);
    } else {
      p.emplace_back(-b, a);
    }
  }
  sort(ALL(m));
  sort(ALL(p));
  ll cur = 0;
  ll max_ = 0;
  REP(i, m.size()) {
    ll a = m[i].first;
    ll b = m[i].second;
    max_ = max(max_, cur + a);
    cur += a - b;
  }
  REP(i, p.size()) {
    ll b = -p[i].first;
    ll a = p[i].second;
    max_ = max(max_, cur + a);
    cur += a - b;
  }
  std::cout << max_ << std::endl;
}