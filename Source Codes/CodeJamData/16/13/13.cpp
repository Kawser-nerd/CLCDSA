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

// k-cycle must be whole thing.
// 2-cycle can support two arms

const int N = 1234;
int bff[N], cycle[N], root[N], maxArm[N];

bitset<N> seen;
int n;
void check(int k) {
	seen.reset();
	seen[k] = true;
	int cur = k;
	int cnt = 0;
	while (true) {
		int nxt = bff[cur];
		cnt++;
		if (seen[nxt]) {
			assert(cnt > 1);
			if (nxt == k) {
				// cycle!
				debugf("cycle found for %d, cnt = %d\n", k, cnt);
				cycle[k] = cnt;
				root[k] = 2;
			} else {
				debugf("arm found for %d, len = %d, root = %d\n", k, cnt, nxt);
				cycle[k] = -1;
				root[k] = nxt;
				maxify(maxArm[nxt], cnt);
			}
			return;
		} else seen[nxt] = true;
		cur = nxt;
	}
}

void readInput() {
	scan_d(n);
	fori (i, 1, n+1) {
		scan_d(bff[i]);
		maxArm[i] = 0;
	}
}

void tc(int tci) {
	readInput();
	fori (i, 1, n+1) {
		check(i);
	}
	int sol = 0;
	seen.reset();
	fori (i, 1, n+1) {
		if (cycle[i] == 2) {
			if (maxArm[i])
				sol += maxArm[i] - cycle[i] + 1;
			else
				sol += 1;
		}
	}
	fori (i, 1, n+1) {
		maxify(sol, cycle[i]);
	}

	printf("Case #%d: %d", tci, sol);
	printf("\n");
}

int main() {
	int tcn;
	scanf("%d", &tcn);
	fori (i, 0, tcn) tc(i+1);
}
