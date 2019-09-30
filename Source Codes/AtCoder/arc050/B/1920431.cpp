#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <array>
#include <deque>
#include <algorithm>
#include <utility>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <numeric>
#include <assert.h>
#include <bitset>
#include <list>
#include <boost/multiprecision/cpp_int.hpp>
using ll = boost::multiprecision::cpp_int;
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define EREP(i, n) for (int i = (n)-1; i >= 0; --i)
#define mod 1000000007
#define pb(a) push_back((a))
#define INF 93193111451418101
#define MIN -93193111451418101
#define EPS 1e-11
#define tp(a, b, c) make_tuple(a, b, c)
using namespace std;
typedef pair<ll, ll> P;

ll r, b, x, y;
ll calc(ll n) {
  ll a = r - n * x;
  ll c = b - n;
  if (a < 0 || c < 0) {
    return 0;
  }
  return n + std::min<ll>(a, c / y);
}
int main() {
  cin >> r >> b >> x >> y;
  ll left = 0, right = r;
  ll mm = (left - right) / 3;
  while (mm) {
    ll m1 = mm + left, m2 = right - mm;
    if (calc(m1) < calc(m2)) {
      left = m1;
    } else {
      right = m2;
    }
    mm = (right - left) / 3;
  }
  ll maxi = 0;
  // cout << left << " " << right << endl;
  for (ll i = left; i <= right; i++) {
    maxi = max(maxi, calc(i));
  }
  cout << maxi << endl;
}