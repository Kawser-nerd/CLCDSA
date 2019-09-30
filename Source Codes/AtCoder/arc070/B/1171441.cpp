// C
#include <cassert>
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
 
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
 
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
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif
 
//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }
 
int dp[5010] = {};
bitset<5010> flag[5010] = {};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, K; cin >> N >> K;
	vector<int> a(N); rep(i, 0, N) { cin >> a[i]; }
	sort(all(a));
	dump(a);
	int ans = N;
	dp[0] = 1;
	rep(i, 1, 5010)flag[i] = ~flag[i];
	rep(i, 0, N) {
		if (a[i] >= K)break;
		rrep(j, 0, K - a[i]) {
			if (dp[j]) {
				dp[j + a[i]] = dp[j];
				bitset<5010> tmp;
				tmp[i] = 1;
				flag[j + a[i]] &= flag[j] | tmp;
			}
		}
	}
	rep(i, 0, N) {
		if (a[i] >= K) {
			ans--;
			continue;
		}
		rep(j, K - a[i], K) {
			if (dp[j]) {
				dump(flag[j]);
				if (flag[j][i])continue;
				dump(i, a[i], j);
				ans--;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
} ./Main.cpp:91:52: warning: implicit conversion from 'long long' to 'const int' changes value from 4557430888798830399 to 1061109567 [-Wconstant-conversion]
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
          ~~~                                      ^~~~~~~~~~~~~~~~~~~~
1 warning generated.