#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <functional>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define REP(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define FOR(i, a, b) for (int i = (a), _n = (b); i <= _n; ++i)
#define FORD(i, a, b) for (int i = (a), _n = (b); i >= _n; --i)
#define FORE(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define ALL(c) (c).begin(), (c).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int INF = 1000000000;

const int VMAX = 2000, EMAX = 4*VMAX;

struct half_edge {
	int dest, rev, face, next;
};
struct graph_edge {
	graph_edge(int dest, int ind): dest(dest), ind(ind) { }
	int dest, ind;
};

int NV;
struct modulo_sorter {
	modulo_sorter(int base): base(base) { }
	bool operator ()(const graph_edge& ae, const graph_edge& be) const {
		int a = ae.dest, b = be.dest;
		a -= base;
		b -= base;
		if (a < 0) a += NV;
		if (b < 0) b += NV;
		return a < b;
	}
	const int base;
};

vector<graph_edge> G[VMAX];

half_edge E[EMAX];
int col[VMAX], res, NE, NF;

inline void add_edge(int u, int v) {
	int ind1 = NE++, ind2 = NE++;
	G[u].PB(graph_edge(v, ind1));
	G[v].PB(graph_edge(u, ind2));
	E[ind1].dest = v;
	E[ind2].dest = u;
	E[ind1].rev = ind2;
	E[ind2].rev = ind1;
}

void dfs_face(int start) {
	E[start].face = NF;
	int next = E[start].next;
	do {
		E[next].face = NF;
		next = E[next].next;
	} while (next != start);
	++NF;
	next = E[start].next;
	do {
		const int u = E[E[next].rev].dest, v = E[next].dest;
		if (u != (v+1)%NV) dfs_face(E[next].rev);
		next = E[next].next;
	} while (next != start);
}

int dfs_count(int start) {
	int cnt = 1, next = E[start].next;
	do {
		++cnt;
		const int u = E[E[next].rev].dest, v = E[next].dest;
		if (u != (v+1)%NV) res = min(res, dfs_count(E[next].rev));
		next = E[next].next;
	} while (next != start);
	return cnt;
}

void dfs_col(int start) {
	const int ustart = E[E[start].rev].dest, vstart = E[start].dest, col1 = col[ustart], col2 = col[vstart];
	int next = E[start].next, cnt = 2, cur_col = 0;
	do {
		const int u = E[E[next].rev].dest, v = E[next].dest;
		if (v != ustart) {
			if (cnt < res) {
				REP(i, 2) if (cur_col == col1 || cur_col == col2) ++cur_col;
				col[v] = cur_col++;
			} else {
				REP(i, 3) if (i != col[u] && i != col[E[E[next].next].dest])
					col[v] = i;
			}
			++cnt;
		}
		if (u != (v+1)%NV) dfs_col(E[next].rev);
		next = E[next].next;
	} while (next != start);
}

void testcase(int ncase) {
	NE = NF = 0;
	int M;
	scanf("%d%d", &NV, &M);
	REP(i, NV) add_edge(i, (i+1)%NV);
	{
		static int beg[VMAX];
		REP(i, M) scanf("%d", beg+i);
		REP(i, M) --beg[i];
		REP(i, M) {
			int x;
			scanf("%d", &x);
			--x;
			add_edge(beg[i], x);
		}
	}
//printf("aha\n");
	REP(i, NV) sort(ALL(G[i]), modulo_sorter(i));
	REP(i, NV) {
		int N = G[i].size();
		REP(j, N) E[E[G[i][j].ind].rev].next = G[i][(j+1)%N].ind;
	}
	dfs_face(1);
//printf("aha\n");
	
	res = INF;
	res = min(res, dfs_count(1));
//printf("aha\n");
	printf("Case #%d: %d\n", ncase, res);

//printf("u = %d v = %d\n", E[E[1].rev].dest, E[1].dest);
	fill_n(col, NV, -1);
	col[E[E[1].rev].dest] = 0;
	col[E[1].dest] = 1;
//REP(i, NV) printf("%d ", col[i]+1); printf("\n");
	dfs_col(1);
	
	REP(i, NV) {
		printf("%d", col[i]+1);
		if (i < NV-1) putchar(' ');
	}
	putchar('\n');
//printf("aha\n");
	
	REP(i, NV) G[i].clear();
}

int main() {
	int T;
	scanf("%d", &T);
	FOR(i, 1, T) testcase(i);
}
