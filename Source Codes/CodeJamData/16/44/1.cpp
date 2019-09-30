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

const int N = 108;
int parent[N];
char grid[N][N];
int n;
void readInput() {
	scan_d(n);
	fgets(grid[0], N, stdin);
	fori (i, 0, n) {
		fgets(grid[i], N, stdin);
	}
}
int root(int a) {
	if (parent[a] == a) return a;
	return parent[a] = root(parent[a]);
}
void link(int a, int b) {
	parent[root(a)] = root(b);
}
typedef pair<int,int> pii;
pii rectacc[N];
map<pii, int> rectangleHistogram;
vector<pii> rectangles;
vector<int> rectangleFreqs;
int squareCost = 0;

void computeRectangles() {
	// Step 1: Compute rectangles with union-find

	squareCost = 0;
	// workers are i, things are n + i
	fori (i, 0, 2*n) {
		parent[i] = i;
	}
	fori (i, 0, n) {
		fori (j, 0, n) {
			if (grid[i][j] == '1') {
				link(i, n + j);
				squareCost--;
			} else {
				assert(grid[i][j] == '0');
			}
		}
	}
	fori (i, 0, 2*n) {
		rectacc[i].first = 0;
		rectacc[i].second = 0;
	}
	fori (i, 0, 2*n) {
		int r = root(i);
		if (i < n) {
			rectacc[r].first++;
		} else {
			rectacc[r].second++;
		}
	}
	rectangleHistogram.clear();
	rectangles.clear();
	rectangleFreqs.clear();
	fori (i, 0, 2*n) {
		if (rectacc[i].first == rectacc[i].second) {
			int cscost = rectacc[i].first * rectacc[i].second;
			debugf("Square cost += %d\n", cscost);
			squareCost += cscost;
		} else {
			rectangleHistogram[rectacc[i]]++;
			debugf("Adding rectangle %d,%d\n", rectacc[i].first, rectacc[i].second);
			// rectangles.push_back(rectacc[i]);
			// rectangleFreqs.push_back(1);
		}
	}
	for (const auto & e : rectangleHistogram) {
		rectangles.push_back(e.first);
		rectangleFreqs.push_back(e.second);
	}
}

bool tick(vector<int> & src, const vector<int> & tgt) {
	assert(src.size() == tgt.size());
	for (size_t i = src.size(); i --> 0; ) {
		assert(0 <= src[i] && src[i] <= tgt[i]);
		if (src[i] < tgt[i]) {
			src[i]++; return true;
		} else {
			src[i] = 0;
		}
	}
	return false;
}
int makeKey(const vector<int> & src, const vector<int> & tgt) {
	int ret = 0;
	for (size_t i = src.size(); i --> 0; ) {
		ret = ret * (tgt[i] + 1) + src[i];
	}
	return ret;
}

pair<int, int> dimensions(const vector<int> & rfs) {
	pair<int, int> ret;
	for (size_t i = rfs.size(); i --> 0; ) {
		ret.first += rfs[i] * rectangles[i].first;
		ret.second += rfs[i] * rectangles[i].second;
	}
	return ret;
}
int maybeSquareDim(const pair<int, int> & rect) {
	if (rect.first == rect.second) {
		return rect.first;
	}
	return -1;
}

map<int, int> bestCost;
const int OO = 1000 << 20;
int getBestCost(const vector<int> & v) {
	int key = makeKey(v, rectangleFreqs);
	if (bestCost.count(key)) {
		return bestCost[key];
	} else {
		return OO;
	}
}
int solve() {
	bestCost.clear();
	bestCost[0] = 0;
	vector<int> s1;
	fori (i, 0, rectangles.size()) {
		s1.push_back(0);
	}
	// we're skipping the all-0s.
	while (tick(s1, rectangleFreqs)) {
		debug(
				debugf("cur tick");
				fori (i, 0, rectangles.size()) {
					debugf(" %d", s1[i]);
				}
				debugf("\n");
		)
		int msd = maybeSquareDim(dimensions(s1));
		int cbc = OO;
		if (msd >= 0) {
			cbc = msd*msd;
			debugf("we split it! %d^2 = %d\n", msd, cbc);
		}
		vector<int> s2;
		fori (i, 0, rectangles.size()) {
			s2.push_back(0);
		}
		vector<int> dual;
		while (tick(s2, s1)) {
			dual.clear();
			fori (j, 0, rectangles.size()) {
				int d = s1[j] - s2[j];
				assert(d >= 0);
				dual.push_back(d);
			}
			debug(
					debugf("    sub tick");
					fori (i, 0, rectangles.size()) {
						debugf(" %d", s2[i]);
					}
					debugf("\n");
					debugf("         dual");
					fori (i, 0, rectangles.size()) {
						debugf(" %d", dual[i]);
					}
					debugf("\n");
			)
			// int dualkey = makeKey(dual, rectangleFreqs);
			int sbc = getBestCost(s2) + getBestCost(dual);
			debugf("       s2key ===> %d\n", makeKey(s2, rectangleFreqs));
			debugf("       dualkey ===> %d\n", makeKey(dual, rectangleFreqs));
			debugf("       sub ===> %d\n", sbc);
			minify(cbc, sbc);
		}
		debugf("curbestcost = %d\n", cbc);
		bestCost[makeKey(s1, rectangleFreqs)] = cbc;
	}
	return bestCost[makeKey(rectangleFreqs, rectangleFreqs)] + squareCost;
}

void tc(int tci) {
	readInput();

	computeRectangles();

	printf("Case #%d: %d", tci, solve());
	printf("\n");
}

int main() {
	int tcn;
	scanf("%d", &tcn);
	fori (i, 0, tcn) tc(i+1);
}
