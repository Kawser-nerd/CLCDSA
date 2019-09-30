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

ll func(ll b, ll n) {
	if (n < b)
		return n;
	return func(b, n/b) + n%b;
}

signed main() {
	int n,l,q;
	scnaf("%d", &n);
	vector<int> h(n);
	REP(i, n) {
		scnaf("%d", &h[i]);
	}

	scanf("%d %d", &l, &q);

	int db[100001][31] = {};
	
	REP(i, n-1) {
		db[i][0] = upper_bound(ALL(h), h[i] + l) - h.begin() - 1;
	}
	db[n - 1][0] = INT_MAX;
		rep(j, 1, 31) {
	REP(i, n) {
		if (db[i][j - 1] == INT_MAX)
			db[i][j] = INT_MAX;
		else 
			db[i][j] = db[db[i][j-1]][j - 1];
		}
	}

	REP(i, q) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--, b--;
		if (b < a)
			swap(a, b);

		int ans = 0;

		int now = a;

		while (now < b) {
			if (b <= db[now][0]) {
				ans++;
				break;
			}
			auto buf = upper_bound(begin(db[now]), end(db[now]), b);
			buf--;
			ans += (1 << (buf - begin(db[now])));
			now = *buf;
		}

		printf("%d\n", ans);
	}

	return 0;
} ./Main.cpp:9:20: warning: extra tokens at end of #include directive [-Wextra-tokens]
#include <stdlib.h>>
                   ^
                   //
1 warning generated.