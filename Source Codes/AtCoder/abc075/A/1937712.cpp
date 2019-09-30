#include <iostream>
#include <cstdio>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <stdlib.h>
#include <functional>
#include <string>

#include <fstream>
#include <iomanip>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#include <unordered_map>
#include <unordered_set>
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

struct Edge {
	int from, to, weight;

	bool operator < (const Edge& obj) const {
		return weight < obj.weight;
	}
	bool operator > (const Edge& obj) const {
		return weight > obj.weight;
	}
};

int mod_pow(ll x, int n, int mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x %mod;
		x = x*x%mod;
		n >>= 1;
	}
	return res;
}

int divmod(int a,int b, int m) { // a/b(mod m)
	// a/b (mod m)
	// a*b^-1
	// b^-1 * b = 1
	// b^(m-1) = 1 
	// b^(m-2) * b = 1
	// b^-1 = b^(m-2)

	// a/b = a * b^(m-2)

	return (a * 1LL * mod_pow(b,m-2, m)) % m;
}

int comb(int n, int r, int mod) {

	int ret = 1,bo = 1;
	REP(i, r) {
		(ret *= n - i)%=MODU;
		(bo *= r-i)%=MODU;
	}

	return divmod(ret, bo, mod);

}

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a == b) cout << c << endl;
	if (a == c) cout << b << endl;
	if (b == c) cout << a << endl;
	return 0;
}