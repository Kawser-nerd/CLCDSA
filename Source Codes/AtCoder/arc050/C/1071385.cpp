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

ll pow10sum(const ll &a, const ll &n, const ll &m) {
  if (n == 0) return 0;
  if (n % 2) return (pow10sum(a, n - 1, m) * a + 1) % m;
  return (pow10sum((a * a) % m, n / 2, m) * (a + 1)) % m;
}

ll pow10(const ll &a, const ll &n, const ll &m) {
  if (n == 0) return 1;
  if (n % 2) return (pow10(a, n - 1, m) * a) % m;
  return pow10((a * a) % m, n / 2, m);
}

void solve(ll A, ll B, ll M){
  ll g = __gcd(A, B);
  ll pa = pow10sum(10, A, M);
  ll pb = pow10sum(pow10(10, g, M), B / g, M);
  cout << (pa * pb) % M << endl;
}

int main(){	
  locale loc(locale(), new yes_no);
  cout << boolalpha << setprecision(12) << fixed;
  cout.imbue(loc);
	ll M;
	ll A;
	ll B;
	scanf("%lld", &A);
	scanf("%lld", &B);
	scanf("%lld", &M);
	solve(A, B, M);
	return 0;
}