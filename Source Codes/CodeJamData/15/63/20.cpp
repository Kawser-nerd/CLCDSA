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

const int OO  = 1000 << 20;
// const int OO2 = 2000 << 20;
// const int       M7  = 1000000007;
// const int       M9  = 1000000009;
// const long long M7L = 1000000007L;
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

struct Frac {
	ll n, d;
	bool operator<(const Frac & c) const {
		return n * c.d < c.n * d;
	}
	bool operator==(const Frac & c) const {
		return n * c.d == c.n * d;
	}
	Frac avg(const Frac & o) const {
		return (Frac) { .n = n * o.d + o.n * d, .d = d * o.d * 2 };
	}
	bool closer(const Frac & center, const Frac & o) const {
		if (*this == o) return false;
		if (*this < o) return center < avg(o);
		else return avg(o) < center;
	}
};
int n;
Frac target;

char s[1000008];
void readInput() {
	int a, b;
	scanf("%d %d.%d %s", &n, &a, &b, s);
	target.d = 1000000;
	target.n = a * 1000000 + b;
	debugf("length = %d\n", n);
}

void tc(int tci) {
	readInput();
	int bestIndex = -1;
	Frac closest = (Frac) { .n = 4, .d = 1 };
	fori (i, 0, n) {
		Frac f = (Frac) { .n = 0, .d = 0 };
		fori (j, i, n) {
			f.n += s[j] - '0';
			f.d++;
			if (f.closer(target, closest)) {
				closest = f;
				debug(
					printf("closer: %lld/%lld\n", closest.n, closest.d);
				)
				bestIndex = i;
			}
		}
	}
	printf("Case #%d: %d", tci, bestIndex);
	printf("\n");
}

int main() {
	int tcn;
	scanf("%d", &tcn);
	fori (i, 0, tcn) tc(i+1);
}
