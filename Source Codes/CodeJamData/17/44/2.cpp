#line 1 "D.cpp"
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cassert>
#include <cmath>
#include <cstring>
#include <functional>
#include <random>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long ll;
#define REP(i,a,n) for (int i = (a); i < (n); i++)

template<class T> T& setmin(T &a, const T &b) {return a = min(a, b);}
template<class T> T& setmax(T &a, const T &b) {return a = max(a, b);}
template<class T> T MODD(const T &a, const T &b) {T r = a%b; if (r < 0) r += b; return r;}




///////////////////////////////// BEGIN util.h /////////////////////////////////


#line 1 "util.h"
template <class T, class U>
ostream& operator<<(ostream &o, const pair<T,U> &p) {
	return o << "(" << p.first << ", " << p.second << ")";
}

template <class T>
ostream& print_list(ostream &o, const T &v) {
	o << "[";
	bool first = true;
	for (const auto &t : v) {
		if (first)
			first = false;
		else
			o << ", ";
		o << t;
	}
	return o << "]";
}

template <class T>
ostream& print_map(ostream &o, const T &v) {
	o << "{";
	bool first = true;
	for (const auto &t : v) {
		if (first)
			first = false;
		else
			o << ", ";
		o << t.first << " => " << t.second;
	}
	return o << "}";
}

template <class T>
ostream& operator<<(ostream &o, const vector<T> &v) {
	return print_list(o, v);
}

template <class T>
ostream& operator<<(ostream &o, const set<T> &v) {
	return print_list(o, v);
}

template <class T,size_t N>
ostream& operator<<(ostream &o, const array<T,N> &v) {
	return print_list(o, v);
}

template <class T,class U>
ostream& operator<<(ostream &o, const map<T,U> &v) {
	return print_map(o, v);
}

template <class T, size_t N>
struct TuplePrintHelper {
	static ostream& print(ostream& o, const T &t) {
		TuplePrintHelper<T,N-1>::print(o, t);
		o << ", ";
		return o << get<N-1>(t);
	}
};

template <class T>
struct TuplePrintHelper<T,1> {
	static ostream& print(ostream& o, const T &t) {
		return o << get<0>(t);
	}
};

template <class T>
struct TuplePrintHelper<T,0> {
	static ostream& print(ostream& o, const T &) {
		return o;
	}
};

template <class... Args>
ostream& operator<<(ostream &o, const tuple<Args...> &t) {
	o << "(";
	TuplePrintHelper<tuple<Args...>, sizeof...(Args)>::print(o, t);
	return o << ")";
}


template <class T>
T fastpow(const T &a, ll n) {
	T r = 1, e = a;
	for (int i = 0; (1ll<<i) <= n; i++, e *= e) {
		if (n&(1ll<<i))
			r *= e;
	}
	return r;
}



///////////////////////////////// END util.h /////////////////////////////////


#line 30 "D.cpp"

int testcasenr;

int X, Y, M;
char line[1000];
char f[200][200];
int ns[200][200];
int nt[200][200];
vector<int> reach[200];
vector<int> bad[200][200];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

const int DOTS = 1000;

int N1, N2; // Number of nodes in $M_1$ and $M_2$
VI ad1[DOTS]; // ad1[a]: Nodes in $M_2$ that are connected to $a\in M_1$
int ni1[DOTS]; // The node in $M_2$ that is matched to $a\in M_1$; -1 if unmatched
int ni2[DOTS]; // The node in $M_1$ that is matched to $a\in M_2$; -1 if unmatched
bool vis[DOTS];
bool visit(int i) {
	if (vis[i])
		return false;
	vis[i] = true;
	for (int k : ad1[i]) {
		if (k != ni1[i] && (ni2[k] == -1 || visit(ni2[k]))) {
			ni1[i] = k;
			ni2[k] = i;
			return true;
		}
	}
	return false;
}
// Returns the size of the maximum bipartite matching / minimum vertex cover
int solve() {
	fill_n(ni1, N1, -1);
	fill_n(ni2, N2, -1);
	int numpairs = 0, pv;
	do {
		pv = numpairs;
		fill_n(vis, N1, false);
		REP(i,0,N1)
		if (ni1[i] == -1)
			numpairs += visit(i);
	} while(numpairs != pv);
	return numpairs;
}

int visgrid[200][200];
void visitgrid(int x, int y, int s, int dist) {
	if (x < 0 || x >= X || y < 0 || y >= Y || f[x][y] == '#' || visgrid[x][y] || dist > M)
		return;
	visgrid[x][y] = true;
	fprintf(stderr, "sol %d vis %d %d\n", s, x, y);
	for (int t : bad[x][y])
		ad1[s].push_back(t);
	REP(d,0,4)
		visitgrid(x+dx[d], y+dy[d], s, dist+1);
}

vector<int> req[200];

bool visreq[200];
void visitreq(int s) {
	if (visreq[s])
		return;
	visreq[s] = true;
	for (int s2 : req[s])
		visitreq(s2);
	if (ni1[s] != -1)
		printf("%d %d\n", s+1, ni1[s]+1);
}

void docase() {
	scanf("%d%d%d ", &X, &Y, &M);
	REP(y,0,Y) {
		scanf("%s ", line);
		REP(x,0,X)
			f[x][y] = line[x];
	}
	int NS = 0, NT = 0;
	REP(y,0,Y) {
		REP(x,0,X) {
			if (f[x][y] == 'S') {
				ns[x][y] = NS;
				NS++;
			}
			if (f[x][y] == 'T') {
				nt[x][y] = NT;
				NT++;
			}
		}
	}
	REP(x,0,X) REP(y,0,Y)
		bad[x][y].clear();
	REP(x0,0,X) REP(y0,0,Y) {
		if (f[x0][y0] == 'T') {
			int t = nt[x0][y0];
			{
				int y = y0;
				for (int x = x0; x < X; x++) {
					if (f[x][y] == '#')
						break;
					bad[x][y].push_back(t);
				}
				for (int x = x0; x >= 0; x--) {
					if (f[x][y] == '#')
						break;
					bad[x][y].push_back(t);
				}
			}
			{
				int x = x0;
				for (int y = y0; y < Y; y++) {
					if (f[x][y] == '#')
						break;
					bad[x][y].push_back(t);
				}
				for (int y = y0; y >= 0; y--) {
					if (f[x][y] == '#')
						break;
					bad[x][y].push_back(t);
				}
			}
		}
	}
	REP(s,0,NS)
		ad1[s].clear();
	REP(x0,0,X) REP(y0,0,Y) {
		if (f[x0][y0] == 'S') {
			REP(a,0,X) REP(b,0,Y)
				visgrid[a][b] = 1E9;
			queue<PII> qu;
			qu.push(PII(x0,y0));
			visgrid[x0][y0] = 0;
			while(!qu.empty()) {
				int x = qu.front().first, y = qu.front().second;
				qu.pop();
				int di = visgrid[x][y];
				if (di <= M) {
					for (int t : bad[x][y]) {
						ad1[ns[x0][y0]].push_back(t);
						fprintf(stderr, "%d -> %d\n", ns[x0][y0], t);
					}
				}
				REP(d,0,4) {
					int xs = x+dx[d], ys = y+dy[d];
					if (xs < 0 || xs >= X || ys < 0 || ys >= Y || f[xs][ys] == '#')
						continue;
					if (visgrid[xs][ys] > di+1) {
						visgrid[xs][ys] = di+1;
						qu.push(PII(xs,ys));
					}
				}
			}
// 			visitgrid(x,y,ns[x][y],0);
		}
	}
	REP(s,0,NS) {
		fprintf(stderr, "%d:", s);
		for (int t : ad1[s])
			fprintf(stderr, " %d", t);
		fprintf(stderr, "\n");
	}
	REP(s,0,NS) {
		req[s].clear();
		visreq[s] = false;
	}
	N1 = NS; N2 = NT;
	int res = solve();
	printf("%d\n", res);
	REP(s,0,NS) {
		if (ni1[s] != -1) {
			for (int t : ad1[s]) {
				if (t == ni1[s])
					break;
				assert(ni2[t] != -1);
				req[s].push_back(ni2[t]);
				fprintf(stderr, "%d req %d\n", s+1, ni2[t]+1);
			}
		}
	}
	REP(s,0,NS)
		visitreq(s);
}

int main() {
	int T;
	scanf("%d ", &T);
	for (testcasenr = 1; testcasenr <= T; testcasenr++) {
		fprintf(stderr, "Test %d/%d\n", testcasenr, T);
		printf("Case #%d: ", testcasenr);
		docase();
		fflush(stdout);
		fflush(stderr);
	}
	return 0;
}
