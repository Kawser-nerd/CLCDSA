// @betaveros v1.1 :: vim:set fdm=marker syntax=cppc:
#define NDEBUG
// #includes, using namespace std {{{
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
// #include <cinttypes> // C++11?
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <new>
#include <algorithm>
#include <iostream>
using namespace std;
// }}}
// #defines, typedefs, constants {{{
#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define fori0(i,e) for(int i = 0; i < ((int)e); i++)
#define fori1(i,e) for(int i = 1; i <= ((int)e); i++)
#define forui(i,s,e) for(unsigned int i = s; i < ((unsigned int)e); i++)
#define foruin(i,c) for(unsigned int i = 0; i < ((unsigned int)(c).size()); i++)
#define _conc(x,y) x ## y
#define _conc2(x,y) _conc(x,y)
#define repeat(n) fori(_conc2(_,__LINE__),0,n)
#define allof(s) (s).begin(), (s).end()
#define scan_d(x) scanf("%d",&(x))
#define scan_dd(x,y) scanf("%d%d",&(x),&(y))
#define scan_ddd(x,y,z) scanf("%d%d%d",&(x),&(y),&(z))
#define scan_dddd(x,y,z,w) scanf("%d%d%d%d",&(x),&(y),&(z),&(w))
#define pushb push_back
#define popb push_back

#ifdef NDEBUG
#define debug(code)
#define debugf(...) ((void)0)
#else
#define debug(code) code
#ifdef CDEBUG
#define debugf(...) fputs("\033[35m", stderr);fprintf(stderr, __VA_ARGS__);fputs("\033[0m", stderr)
#else
#define debugf(...) fprintf(stderr, __VA_ARGS__)
#endif
#endif
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> Vint;
typedef vector<int>::iterator Vit;

// const int OO  = 1000 << 20;
// const int OO2 = 2000 << 20;
const int       M7  = 1000000007;
// const int       M9  = 1000000009;
const long long M7L = 1000000007L;
// }}}
// dump, min/maxify {{{
template <class T> void dumpBetween(const T & a, const T & b) {
	for (T it = a; it != b; it++) cout << *it << " ";
	cout << endl;
}
template <class T> void dumpAll(const T & a) { dumpBetween(allof(a)); }
template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }
// }}}

// basic: mod, msq, mpow {{{
long long mod(long long x, long long m) {
	long long r = x % m;
	return r < 0 ? r + m : r;
}
long long msq(long long x, long long m) {
	// warning, assumes x is "small"
	return mod(x * x, m);
}
long long mpow(long long b, long long e, long long m) {
	if (e == 0) return 1;
	if (e == 1) return b;
	long long h = msq(mpow(b, e / 2, m), m);
	return (e & 1) ? mod(h * b, m) : h;
}
// }}}
long long minv(long long x, long long m) {
	return x == 1 ? 1 : mod(minv(m % x, m) * (m - m/x), m);
}

ll factorial[1000008];
ll factorialInverse[1000008];
ll derangements[1000008];
void prep() {
	factorial[0] = 1;
	factorialInverse[0] = 1;
	fori (i, 1, 1000008) {
		factorial[i] = mod(factorial[i - 1] * i, M7L);
		factorialInverse[i] = minv(factorial[i], M7L);
	}
	derangements[0] = 1;
	derangements[1] = 0;
	fori (i, 2, 1000008) {
		// ?????????????????????????????????????????????????????????
		derangements[i] = mod((i - 1) * (derangements[i-1] + derangements[i-2]), M7L);
	}
}

int x, n;
void readInput() {
	scan_dd(n, x);
}
ll solve() {
	ll r = 0;
	fori (i, x, n+1) r = mod(r +
			mod(mod(derangements[n-i] * factorialInverse[i], M7L) * factorialInverse[n - i], M7L), M7L);
	return mod(mod(r * factorial[n], M7L) * factorial[n], M7L);
}

void tc(int tci) {
	readInput();

	printf("Case #%d: %lld", tci, solve());
	printf("\n");
}

int main() {
	prep();
	debug (
		printf("derangements\n");
		fori (i, 0, 10) {
			printf("%lld\n", derangements[i]);
		}
	)
	int tcn;
	scanf("%d", &tcn);
	fori (i, 0, tcn) tc(i+1);
}
