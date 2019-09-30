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

template<typename T>
vector<T> table(int n, T v) { return vector<T>(n, v); }

template <class... Args>
auto table(int n, Args... args) {
  auto val = table(args...);
  return vector<decltype(val)>(n, move(val));
}

struct yes_no : numpunct<char> {
  string_type do_truename()  const { return "Yes"; }
  string_type do_falsename() const { return "No"; }
};

void solve(ll N, vector<ll> A) {
  sort(A.rbegin(), A.rend());
  ll res = 0;
  REP(i,N) {
    if (i % 2 == 0) res += A[i];
  }
  cout << res << endl;
}

int main() {
  locale loc(locale(), new yes_no);
  cout << boolalpha << setprecision(12) << fixed;
  cout.imbue(loc);
	ll N;
	scanf("%lld", &N);
	vector<ll> A(N-1+1);
	for (int i = 0 ; i <= N-1 ; i++) {
	  scanf("%lld", &A[i]);
	}
	solve(N, A);
	return 0;
}