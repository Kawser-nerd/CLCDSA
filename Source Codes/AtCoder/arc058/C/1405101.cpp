#include <iostream>
#include <cstdio>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <stdlib.h>>
#include <functional>
#include <string>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#include <unordered_map>
#include <nmmintrin.h>
#include <chrono>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) <= (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define MODU 1000000007
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
#define MP(a,b) make_pair((a),(b))
#define Manh(a,b) (abs((a).first-(b).first) + abs((a).second - ((b).second))
#define pritnf printf
#define scnaf scanf
#define itn int
#ifdef _MSC_VER
#define __builtin_popcount _mm_popcnt_u32
#define __builtin_popcountll _mm_popcnt_u64
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*)array, (T*)(array + N), val);
}

int parse(int ne, vector<int>& v) {
	int buf = (1 << ne) | 1;
	int p = ne;
	for (auto itr : v) {
		bitset(buf, p + itr);
		p += itr;
	}
	return buf;
}

ll dp[41][131072] = {};
int n, x, y, z;
ll func(int ps, int st) {
	st %= 131072;
	if (dp[ps][st])
		return dp[ps][st];
	if (ps >= n)
		return 1;
	int buf = st;
	ll ret = 0;
	rep(i, 1, 11) {
		int cur = buf << i;
		cur |= 1;
		if (!(bitcheck(cur, z) && bitcheck(cur, y + z) && bitcheck(cur, x + y + z))) {
			ret += func(ps + 1, cur);
			ret %= MODU;
		}
		else
			printf("");
	}
	return dp[ps][st] = ret;
}

ll mod_pow(ll x, ll n, ll mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x %mod;
		x = x*x%mod;
		n >>= 1;
	}
	return res;
}
signed main() {

	scanf("%d %d %d %d", &n, &x, &y, &z);

	printf("%d\n", (mod_pow(10,n, MODU) - func(0, 1) + MODU) % MODU);

	return 0;
} ./Main.cpp:9:20: warning: extra tokens at end of #include directive [-Wextra-tokens]
#include <stdlib.h>>
                   ^
                   //
./Main.cpp:60:17: warning: operator '<<' has lower precedence than '+'; '+' will be evaluated first [-Wshift-op-parentheses]
                bitset(buf, p + itr);
                ~~~~~~~~~~~~~~^~~~~~
./Main.cpp:32:39: note: expanded from macro 'bitset'
#define bitset(a,b)      ( a |= (1 << b))
                                   ~~ ^
./Main.cpp:60:17: note: place parentheses around the '+' expression to silence this warning
                bitset(buf, p + itr);
                            ~~^~~~~
./Main.cpp:32:39: note: expanded from macro 'bitset'
#define bitset(a,b)      ( a |= (1 << b))
                                      ^
./Main.cpp:79:45: warning: operator '>>' has lower precedence than '+'; '+' will be evaluated first [-Wshift-op-parentheses]
                if (!(bitcheck(cur, z) && bitcheck(cur, y + z) && bitcheck(cur, x + y + z))) {
                   ...