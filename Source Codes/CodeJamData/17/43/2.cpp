#line 1 "C.cpp"
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


#line 30 "C.cpp"

int testcasenr;

const int DOTS = 1E6;

int A, V; // Number of conditions (a or b) that have to be fulfilled, number of variables
bool condsig[DOTS][2]; // The ``sign'' of the part of the condition (\verb|false| means ``not'')
int condvar[DOTS][2]; // Number of the variable in the part of the condition
bool solution[DOTS]; // A possible assignment of variables; not necessary if the question is just WHETHER there is a solution

VI adj[DOTS], radj[DOTS];
bool vis[DOTS];
VI order;
int comp[DOTS];
int compnr;
VI incomp[DOTS], adjcomp[DOTS]; // not necessary if the question is just WHETHER there is a solution
bool viscomp[DOTS], isset[DOTS]; // not necessary if the question is just WHETHER there is a solution

void visitcomp(int i) { // not necessary if the question is just WHETHER there is a solution
	if (viscomp[i])
		return;
	viscomp[i] = true;
	for (int k : adjcomp[i])
		visitcomp(k);
	isset[i] = true;
	for (int k : incomp[i])
		solution[k/2] = (isset[comp[incomp[i][0]^1]]+k)%2;
}

void findsolution() { // not necessary if the question is just WHETHER there is a solution
	REP(i,0,compnr) {
		incomp[i].clear();
		adjcomp[i].clear();
		viscomp[i] = false;
		isset[i] = false;
	}
	REP(i,0,2*V) {
		incomp[comp[i]].push_back(i);
		for (int k : adj[i])
			adjcomp[comp[i]].push_back(comp[k]);
	}
	REP(i,0,compnr)
	visitcomp(i);
}

VI *cadj;
void dfs(int i) {
	if(vis[i])
		return;
	vis[i] = true;
	comp[i] = compnr;
	for (int k : cadj[i])
		dfs(k);
	order.push_back(i);
}

bool solve() { // Returns whether all conditions are simultaneously satisfiable
	REP(i,0,2*V) {
		adj[i].clear();
		radj[i].clear();
	}
	REP(i,0,A) {
		int v0 = 2*condvar[i][0]+condsig[i][0];
		int v1 = 2*condvar[i][1]+condsig[i][1];
		adj[v0^1].push_back(v1);
		radj[v1].push_back(v0^1);
		adj[v1^1].push_back(v0);
		radj[v0].push_back(v1^1);
	}
	fill_n(vis, 2*V, false);
	order.clear();
	cadj = adj;
	REP(i,0,2*V)
	dfs(i);
	fill_n(vis, 2*V, false);
	compnr = 0;
	cadj = radj;
	for (int i = 2*V-1; i >= 0; i--)
		if (!vis[order[i]]) {
			dfs(order[i]);
			compnr++;
		}
		REP(i,0,V)
		if (comp[2*i] == comp[2*i+1])
			return false;
		findsolution(); // not necessary if the question is just WHETHER there is a solution
		return true;
}

int X, Y;
char line[1000];
char f[1000][1000];

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

int beam(int d, char c) {
	if (c == '.')
		return d;
	if (c == '-' || c == '|')
		return -1;
	if (c == '/')
		return d^1;
	if (c == '\\')
		return d^3;
	if (c == '#')
		return -2;
	fprintf(stderr, "hi '%c'\n", c);
	assert(false);
}

vector<PII> pointstart[100][100];

void docase() {
	scanf("%d%d ", &Y, &X);
	REP(y,0,Y) {
		scanf("%s ", line);
		REP(x,0,X)
			f[x][y] = line[x];
	}
	/*REP(y,0,Y) {
		REP(x,0,X)
		fprintf(stderr, "%c", f[x][y]);
		fprintf(stderr, "\n");
	}*/
	
	A = 0; V = 0;
	REP(x,0,X) REP(y,0,Y)
		pointstart[x][y].clear();
	
	REP(x0,0,X) REP(y0,0,Y) {
		if (f[x0][y0] == '-' || f[x0][y0] == '|') {
			REP(s,0,2) {
				bool ok = true;
				for (int d0 = s; d0 < 4; d0 += 2) {
					int d = d0;
					int x = x0+dx[d], y = y0+dy[d];
					while(0 <= x && x < X && 0 <= y && y < Y) {
						d = beam(d, f[x][y]);
// 						fprintf(stderr, "vis %d %d %d (%d %d %d)\n", x, y, d, x0, y0, d0);
						if (d == -1)
							ok = false;
						if (d < 0)
							break;
						x += dx[d];
						y += dy[d];
					}
				}
				if (!ok) {
// 					fprintf(stderr, "not ok: %d %d, %d\n", x0, y0, s);
					condsig[A][0] = 1-s;
					condsig[A][1] = 1-s;
					condvar[A][0] = V;
					condvar[A][1] = V;
					A++;
				} else {
// 					fprintf(stderr, "ok: %d %d, %d\n", x0, y0, s);
					for (int d0 = s; d0 < 4; d0 += 2) {
						int d = d0;
						int x = x0+dx[d], y = y0+dy[d];
						while(0 <= x && x < X && 0 <= y && y < Y) {
							if (f[x][y] == '.')
								pointstart[x][y].push_back(PII(V, s));
							d = beam(d, f[x][y]);
							if (d < 0)
								break;
							x += dx[d];
							y += dy[d];
						}
					}
				}
			}
			V++;
		}
	}
	
	REP(x,0,X) REP(y,0,Y) {
		if (f[x][y] == '.') {
			assert(pointstart[x][y].size() <= 2);
			if (pointstart[x][y].size() == 0) {
				printf("IMPOSSIBLE\n");
				return;
			} else if (pointstart[x][y].size() == 1) {
				REP(t,0,2) {
					condsig[A][t] = pointstart[x][y][0].second;
					condvar[A][t] = pointstart[x][y][0].first;
				}
			} else if (pointstart[x][y].size() == 2) {
				REP(t,0,2) {
					condsig[A][t] = pointstart[x][y][t].second;
					condvar[A][t] = pointstart[x][y][t].first;
				}
			}
			A++;
		}
	}
	
	if (!solve()) {
		printf("IMPOSSIBLE\n");
		return;
	}
	
	printf("POSSIBLE\n");
	V = 0;
	REP(x0,0,X) REP(y0,0,Y) {
		if (f[x0][y0] == '-' || f[x0][y0] == '|') {
			f[x0][y0] = (solution[V] ? '|' : '-');
			V++;
		}
	}
	REP(y,0,Y) {
		REP(x,0,X)
			printf("%c", f[x][y]);
		printf("\n");
	}
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
