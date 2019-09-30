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

template<int MOD>
struct ModInt {
	static const ll Mod = MOD;
	unsigned x;
	ModInt() : x(0) {}
	ModInt(signed long long sig) { ll sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
	int get() const { return (ll)x; }

	ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
	ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
	ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }

	ModInt inverse() const {
		signed long long a = x, b = MOD, u = 1, v = 0;
		while (b) {
			signed long long t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		if (u < 0) u += Mod;
		ModInt res; res.x = (unsigned long long )u;
		return res;
	}
};
typedef ModInt<1000000007> mint;

mint factorial(mint n) {//??
	if (n.get() > 0) {
		return (n * factorial(n - 1));
	}
	else {
		return 1;
	}
}


mint ncr(mint n, mint r) {
	return factorial(n) / (factorial(r) * (factorial(n - r)));
}

signed main() {

	int h, w,a,b;
	scanf("%d %d %d %d", &h, &w, &a, &b);

	mint f = ncr(h-a-1 + b, h-a-1), e = ncr(w-b-1 + a-1,a-1);
	mint ans = 0;
	rep(i, h - a - 1 + b, h-a-1 + w) {
		ans += f * e;

		if (h - a > 1) {
			f *= h - a - 1;
			f /= (i - (h - a - 1)) + 1;
			f *= (i + 1);
			f /= h - a - 1;
		}

		if (a > 1) {
			e *= a - 1;
			e /= (h + w - i - 3);
			e *= (h + w - i - 3 - (a - 1));
			e /= a - 1;
		}
	}
	printf("%d\n",ans.get());
	return 0;
} ./Main.cpp:9:20: warning: extra tokens at end of #include directive [-Wextra-tokens]
#include <stdlib.h>>
                   ^
                   //
1 warning generated.