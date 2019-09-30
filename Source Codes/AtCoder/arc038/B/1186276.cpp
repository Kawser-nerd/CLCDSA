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
  string_type do_truename()  const { return "First"; }
  string_type do_falsename() const { return "Second"; }
};

ll H, W;
 
const int dy[3] = {1, 1, 0};
const int dx[3] = {1, 0, 1};
 
int memo[128][128];

int dp(const vector<string> &S, int y, int x) {
  if (y >= H || x >= W || S[y][x] == '#') return 1;
  if (memo[y][x] >= 0) return memo[y][x];
  REP(dir,3) {
    if (dp(S, y + dy[dir], x + dx[dir]) == 0)
      return memo[y][x] = 1;
  }
  return memo[y][x] = 0;
}

void solve(vector<string> S) {
  memset(memo, -1, sizeof(memo));
  cout << !!dp(S, 0, 0) << endl;
}

int main() {
  locale loc(locale(), new yes_no);
  cout << boolalpha << setprecision(12) << fixed;
  cout.imbue(loc);
	scanf("%lld", &H);
	vector<string> S(H-1+1);
	scanf("%lld", &W);
	for (int i = 0 ; i <= H-1 ; i++) {
	  cin >> S[i];
	}
	solve(S);
	return 0;
}