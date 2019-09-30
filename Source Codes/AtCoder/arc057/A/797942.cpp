#define _GLIBCXX_DEBUG //compiles STL in debug mode
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <functional>
#include <numeric>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <queue>
#include <stack>
#include <set>
#include <limits>

using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define ASC_SORT(c) sort(ALL(c))
#define DESC_SORT(c) sort(ALL(c), greater<int>())
#define MAX3(a,b,c) max(max((a),(b)),(c))
#define MIN3(a,b,c) min(min((a),(b)),(c))
#define MAXN(t) numeric_limits<t>::max()
#define MINN(t) numeric_limits<t>::min()

using ll = long long;
using ull = unsigned long long;
template<typename T> class p : pair<T, T> {
  T &x = pair<T, T>::first, &y = pair<T, T>::first;
};
//template<typename T> using p = pair<T, T>;
using ld = long double;
using pld = p<ld>;
template<typename T> using v = vector<T>;
using vpld = v<pld>;

constexpr ld EPS {1e-11};
int sgn(const ld& r) { return (r > EPS) - (r < -EPS); }
int sgn(const ld& a, const ld& b) { return sgn(a - b); }
bool eq(const ld& a, const ld& b) { return sgn(a, b) == 0; }

//TODO: implement MAXN, MINN as constexpr
//calc sums via accumulate

template<typename T> void rep(T init, T n, function<void(T)> f) {
  for(T i {init}; i < n; i++) f(i);
}
ll operator*(ll n, function<void(void)> f) {
  for(ll i {0}; i < n; i++) f();
  return 0;
}

template<typename C, typename D>
D fmap(function<typename D::value_type(typename C::value_type)> f, C c) {
  D ret;
  transform(c.begin(), c.end(), back_inserter(ret), f);
  return ret;
}

template<typename C>
C ffilter(function<bool(typename C::value_type)> f, C c) {
  C ret;
  remove_copy_if(c.begin(), c.end(), back_inserter(ret),
    [&f](typename C::value_type e){ return !f(e); });
  return ret;
}

template<typename C, typename T>
T ffold(function<T(T, typename C::value_type)> f, T init, C c) {
  return accumulate(c.begin(), c.end(), init, f);
}
template<typename C>
typename C::value_type ffold(function<typename C::value_type(typename C::value_type, typename C::value_type)> f, C c) {
  return accumulate(c.begin()+1, c.end(), *c.begin(), f);
}

template<typename C>
C frange(typename C::value_type begin, typename C::value_type end) {
  C ret;
  for(auto i = begin; i != end; i++) ret.push_back(i);
  return ret;
}

int main()
{
  ios::sync_with_stdio(false); //USE "\n" INSTEAD OF endl. Do NOT use printf.
  cin.tie(0);
  long long a, k, ans {0};
  cin >> a >> k;
  if (k == 0) {
    cout << 2000000000000LL - a << endl;
  } else {
    while(a < 2000000000000LL) {
      a += 1 + k*a;
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}