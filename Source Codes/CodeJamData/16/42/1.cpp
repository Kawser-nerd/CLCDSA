// @betaveros v1.1 :: vim:set fdm=marker syntax=cppc:
// #define NDEBUG
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

const int N = 208;
double prob[208];
double prefix[N][N];
double suffix[N][N];
int n, k;
void readInput() {
	scan_dd(n, k);
	fori (i, 0, n) {
		scanf("%lf", &prob[i]);
	}
}

void tc(int tci) {
	readInput();

	sort(prob, prob + n);

	prefix[0][0] = 1;
	fori (i, 0, n) { // index of person (+1 = length of prefix)
		fori (j, 0, i+2) { // number of yesses
			prefix[i+1][j] = prefix[i][j] * (1 - prob[i]);
			if (j) prefix[i+1][j] += prefix[i][j-1] * prob[i];
		}
	}
	
	suffix[0][0] = 1;
	fori (i, 0, n) { // ~ index of person (+1 = length of suffix)
		fori (j, 0, i+2) { // number of yesses
			suffix[i+1][j] = suffix[i][j] * (1 - prob[n - 1 - i]);
			if (j) suffix[i+1][j] += suffix[i][j-1] * prob[n - 1 - i];
		}
	}

	double best = 0;
	fori (plen, 0, k+1) {
		int slen = k - plen;

		double tie = 0;
		fori (pyes, 0, k/2 + 1) {
			tie += prefix[plen][pyes] * suffix[slen][k/2 - pyes];
		}
		maxify(best, tie);
	}

	printf("Case #%d: %.15lf", tci, best);
	printf("\n");
}

int main() {
	int tcn;
	scanf("%d", &tcn);
	fori (i, 0, tcn) tc(i+1);
}
