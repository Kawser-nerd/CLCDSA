#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
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

#define int ll

int n, wsum;
int w[101], v[101];
int dp[101][301][101];
int base;

int func(int cur,int wc, int cou) {
	if (dp[cur][wc][cou] != -1) return dp[cur][wc][cou];
	if (cur == n) {
		if (wc > (wsum - base*cou))
			return INT_MIN;
		return 0;
	}
	int ret = INT_MIN;
	ret = max(ret,func(cur+1, wc,cou));
	ret = max(ret,func(cur+1, wc + w[cur], cou + 1) + v[cur]);

	return dp[cur][wc][cou] = ret;
}

signed main() {
	scanf("%lld %lld", &n, &wsum);
	REP(i, n) {
		scanf("%d %d", &w[i], &v[i]);
		if (!i)base = w[0];
		w[i] -= base;
	}
	Fill(dp,-1);
	printf("%lld\n", func(0, 0, 0));

	return 0;
} ./Main.cpp:77:18: warning: format specifies type 'int *' but the argument has type 'll *' (aka 'long long *') [-Wformat]
                scanf("%d %d", &w[i], &v[i]);
                       ~~      ^~~~~
                       %lld
./Main.cpp:77:25: warning: format specifies type 'int *' but the argument has type 'll *' (aka 'long long *') [-Wformat]
                scanf("%d %d", &w[i], &v[i]);
                          ~~          ^~~~~
                          %lld
2 warnings generated.