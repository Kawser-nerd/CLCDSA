#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

#define times(n, i)      uptil(0, n, i)
#define rtimes(n, i)     downto((n) - 1, 0, i)
#define upto(f, t, i)    for(auto i##0_to = (t), i = decltype(t)(f); i <= i##0_to; i++)
#define uptil(f, t, i)   for(auto i##0_to = (t), i = decltype(t)(f); i <  i##0_to; i++)
#define downto(f, t, i)  for(auto i##0_to = decltype(f)(t), i = (f); i >= i##0_to; i--)
#define downtil(f, t, i) for(auto i##0_to = decltype(f)(t), i = (f); i >  i##0_to; i--)
// types
	using LD = long double;
	#define double LD
	#define long long long
	#define int long
	using VB = vector<bool>;   using WB = vector<VB>;
	using VC = vector<char>;   using WC = vector<VC>;
	using VI = vector<int>;    using WI = vector<VI>;
	using VD = vector<double>; using WD = vector<VD>;
	using VS = vector<string>; using WS = vector<VS>;
	using PI = pair<int, int>;
	using TI = tuple<int, int, int>;
	using VPI = vector<PI>;    using WPI = vector<VPI>;

bool debug;
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 2
#define _LIBCPP_DEBUG2 2
#define ln << '\n'
#define tb << '\t'
#define sp << ' '
#define db(x) if(debug) cerr << #x << " = " << (x) << ", "
#define dbg(x) if(debug) cerr << #x << " = " << (x) ln

void solve();

signed main(signed argc, char *argv[]) {
	#ifdef EBUG
		debug = true;
	#elif defined(ONLINE_JUDGE)
		debug = false;
	#else
		debug = argc >= 2;
	#endif
	if(!debug) {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
	cout << fixed << setprecision(20);
	cerr << fixed << setprecision(20);

	solve();

	return 0;
}

/******************************* basic library ********************************/
// IO
	template<class T>
	istream& operator>>(istream& s, vector<T>& v) {
		for(auto&& p : v) s >> p; return s;
	}
	template<class T>
	ostream& operator<<(ostream& s, vector<T> v) {
		int i = 0;
		for(const auto& p : v) s << (i++?" ":"") << p;
		return s;
	}
	template<class T>
	ostream& operator<<(ostream& s, vector<vector<T>> w) {
		for(const auto& v : w) {
			int i = 0;
			for(const auto& p : v) s << (i++?" ":"") << p;
			s ln;
		}
		return s;
	}
	template<class T> T& RD(T& t) { cin >> t; return t; }
	template<class T, class... A> T RD(A... a) { T t(a...); cin >> t; return t; }
// container
	#define all(v) (v).begin(), (v).end()
	template<class T> T max(const pair<T, T>& p) { return max(p.first, p.second); }
	template<class T> T min(const pair<T, T>& p) { return min(p.first, p.second); }
// other
	#define b_max(x, y) x = max(x, y)
	#define b_min(x, y) x = min(x, y)
	inline LD AC(LD d) { return d ? d : 0; }
constexpr long INF = 1LL << 60;
constexpr long MOD = 1000000009; // 1000000007; // 998244353;

/****************************** optional library ******************************/


/************************************ main ************************************/

int N, M;
map<int, int> path[100010] = {};
int x[100010] = {};
bool visited[100010] = {};

void dfs(int i, int y) {
	if(x[i] == INF) x[i] = y;
	if(x[i] != y) {
		cout << "No" ln;
		exit(0);
	}
	if(visited[i]) return;
	visited[i] = true;
	for(auto& p : path[i]) {
		int j, t; tie(j, t) = p;
		dfs(j, y + t);
	}
}

void solve() {
	int N, M; scanf("%lld%lld", &N, &M);
	times(N, i) x[i] = INF;
	times(M, i) {
		int U, V, D; scanf("%lld%lld%lld", &U, &V, &D);
	    path[U-1][V-1] = D;
	    path[V-1][U-1] = -D;
	}
	times(N, i) {
		if(!visited[i]) dfs(i, 0);
	}

	cout << "Yes" ln;
}