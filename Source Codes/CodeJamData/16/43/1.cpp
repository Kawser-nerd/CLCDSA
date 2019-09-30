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

typedef pair<int,int> pii;
const int N = 308;
int nRows, nCols;
int n;
int match[N];

void readInput() {
	scan_dd(nRows, nCols);
	n = (nRows + nCols) * 2;
	fori (i, 0, n / 2) {
		int a, b;
		scan_dd(a, b);
		match[a-1] = b;
		match[b-1] = a;
	}
}

bool areMatch(const pii& a, const pii& b) {
	bool f1 = a.first == b.second;
	bool f2 = a.second == b.first;
	assert(f1 == f2);
	return f1;
}

char grid[N][N];
bool ok;

struct Loc {
	int r, c;
	Loc(int rr, int cc): r(rr), c(cc) {}
	Loc operator+(const Loc & o) const {
		return Loc(r + o.r, c + o.c);
	}
	bool operator==(const Loc & o) const {
		return r == o.r && c == o.c;
	}
	bool operator!=(const Loc & o) const {
		return r != o.r || c != o.c;
	}
	Loc forward() const {
		return Loc(-c, -r);
	}
	Loc backward() const {
		return Loc(c, r);
	}
	Loc turnRight() const {
		return Loc(c, -r);
	}
	Loc turn(char ch) const {
		if (ch == '/') return forward();
		if (ch == '\\') return backward();
		throw "turn failed, not / or \\";
	}
	char veer() const {
		assert(abs(r) + abs(c) == 1);
		if (forward() == turnRight()) return '/';
		if (backward() == turnRight()) return '\\';
		throw "veer failed??";
	}
	void print() const {
		fprintf(stderr, "Loc(%d,%d)\n", r, c);
	}
};

pair<Loc,Loc> getLoc(int id) {
	assert(id > 0);
	if (1 <= id && id <= nCols) {
		return make_pair(Loc(-1, id - 1), Loc(1, 0));
	}
	id -= nCols;
	if (1 <= id && id <= nRows) {
		return make_pair(Loc(id - 1, nCols), Loc(0, -1));
	}
	id -= nRows;
	if (1 <= id && id <= nCols) {
		return make_pair(Loc(nRows, nCols - id), Loc(-1, 0));
	}
	id -= nCols;
	assert(id <= nRows);
	return make_pair(Loc(nRows - id, -1), Loc(0, 1));
}

bool inRange(const Loc & loc) {
	return 0 <= loc.r && loc.r < nRows && 0 <= loc.c && loc.c < nCols;
}

void link(int a, int b) {
	debugf("linking %d %d\n", a, b);

	auto startpair = getLoc(a);
	auto endpair = getLoc(b);
	Loc curpos = startpair.first;
	Loc curdir = startpair.second;
	Loc endpos = endpair.first;
	// [ .-> ]
	while (true) {
		curpos = curpos + curdir;
		// ->[ ... ]
		if (curpos == endpos) { return; }
		if (!inRange(curpos)) { ok = false; return; }
		
		char curch;
		switch (grid[curpos.r][curpos.c]) {
			case '.':
				curch = curdir.veer();
				grid[curpos.r][curpos.c] = curch;
				curdir = curdir.turn(curch);
				break;
			default:
				curdir = curdir.turn(grid[curpos.r][curpos.c]);
		}
	}
}

void tc(int tci) {
	readInput();

	// reset
	ok = true;
	fori (i, 0, nRows) {
		fori (j, 0, nCols) {
			grid[i][j] = '.';
		}
		grid[i][nCols] = '\0';
	}

	vector<pii> stk;
	fori (i, 0, n) {
		pii cur = make_pair(i + 1, match[i]);
		if (stk.size() && areMatch(stk.back(), cur)) {
			link(cur.first, cur.second);
			if (!ok) break;
			stk.pop_back();
		} else {
			stk.push_back(cur);
		}
	}


	printf("Case #%d:\n", tci);
	if (ok && !stk.size()) {
		fori (i, 0, nRows) {
			fori (j, 0, nCols) {
				if (grid[i][j] == '.') grid[i][j] = '/';
			}
			puts(grid[i]);
		}
	} else {
		puts("IMPOSSIBLE\n");
	}
}

int main() {
	int tcn;
	scanf("%d", &tcn);
	fori (i, 0, tcn) tc(i+1);
}
