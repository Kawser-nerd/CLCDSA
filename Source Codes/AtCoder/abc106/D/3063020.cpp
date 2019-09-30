#ifdef LOCAL111
	#define _GLIBCXX_DEBUG
#else
	#define NDEBUG
#endif
#define _USE_MATH_DEFINES
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
#include <type_traits>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>
#endif
const int INF = 1e9;
using namespace std;
template<typename T, typename U> ostream& operator<< (ostream& os, const pair<T,U>& p) { os << '(' << p.first << ' ' << p.second << ')'; return os; }

#define endl '\n'
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) int((a).size())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#ifdef LOCAL111
	#define DEBUG(x) cout<<#x<<": "<<(x)<<endl
	template<typename T> void dpite(T a, T b){ for(T ite = a; ite != b; ite++) cout << (ite == a ? "" : " ") << *ite; cout << endl;}
#else
	#define DEBUG(x) true
	template<typename T> void dpite(T a, T b){ return; }
#endif
#define F first
#define S second
#define SNP string::npos
#define WRC(hoge) cout << "Case #" << (hoge)+1 << ": "
template<typename T> void pite(T a, T b){ for(T ite = a; ite != b; ite++) cout << (ite == a ? "" : " ") << *ite; cout << endl;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}

typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int,int> P;

void ios_init(){
	//cout.setf(ios::fixed);
	//cout.precision(12);
#ifdef LOCAL111
	return;
#endif
	ios::sync_with_stdio(false); cin.tie(0);
}

int main()
{
	ios_init();
	int n, m, q;
	cin >> n >> m >> q;
	vector<int> l(m), r(m);
	REP(i, m) {
		cin >> l[i] >> r[i];
		l[i]--;
	}


	vector<int> pv(q), qv(q);
	REP(i, q) {
		cin >> pv[i] >> qv[i];
		pv[i]--;
	}

	vector<vector<int>> imo(n);
	REP(i, m) {
		imo[l[i]].push_back(r[i]);
	}
	REP(i, n) {
		sort(ALL(imo[i]));
	}

	REP(i, q) {
		LL ans = 0;
		FOR(j, pv[i], qv[i]) {
			ans += upper_bound(ALL(imo[j]), qv[i]) - imo[j].begin();
		}
		cout << ans << endl;
	}


	return 0;
}