#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <locale>
#include <iostream>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

using ll = long long;
using ld = long double;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
template <typename T> int len(const T &x) { return x.size(); }

struct yes_no : numpunct<char> {
  string_type do_truename()  const { return "Yes"; }
  string_type do_falsename() const { return "No"; }
};

ll solve(ll R, ll B, ll x, ll y){
  if (R > B) { return solve(B, R, y, x); }
  ll block = B / 2 / y;
  if (block == 0) {
    ll res = R / x;
    if (B >= y && R >= 1) chmax(res, solve(R - 1, B - y, x, y) + 1);
    return res;
  }
  return min(R, solve(R - block, B - y * block, x, y) + block);
}

int main(){	
  locale loc(locale(), new yes_no);
  cout << boolalpha << setprecision(12) << fixed;
  cout.imbue(loc);
	ll x;
	ll y;
	ll B;
	ll R;
	scanf("%lld", &R);
	scanf("%lld", &B);
	scanf("%lld", &x);
	scanf("%lld", &y);
	cout << solve(R, B, x, y) << endl;
	return 0;
}