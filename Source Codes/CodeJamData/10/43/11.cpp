#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cassert>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
typedef long double ld;
typedef pair<int,int> PII;
typedef vector<int> VI;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()

/* COMPETITION CODE */

#define MAXN 1010
int father[MAXN];
int N;

void correct (int t, int f) {
	if (father[t] == -1) return;
	correct(father[t], f);
	father[t] = f;
}

int find (int t) {
	int nt = t;
	while (father[nt] != -1) nt = father[nt];
	correct(t, nt);
	return nt;
}

void join (int a, int b) {
	if (find(a) == find(b)) return;
	father[find(a)] = find(b);
}

typedef struct rect {
	int x1, x2, y1, y2;
	rect (int xa, int xb, int ya, int yb) {x1 = xa; x2 = xb; y1 = ya; y2 = yb;}
	rect () {};
} rect;

rect rs[MAXN];

inline int between (int a, int b, int c) {
	if (a <= b && b <= c) return 1;
	return 0;
}

inline int overlap (int y1, int y2, int y3, int y4) {
	if (between(y1, y3, y2+1)) return 1;
	if (between(y3, y1, y4+1)) return 1;
	return 0;
}

int touch (const rect &R1, const rect &R2) {
	if (between(R1.x1, R2.x1, R1.x2) && overlap(R1.y1, R1.y2, R2.y1, R2.y2)) return 1;
	if (between(R1.x1, R2.x2, R1.x2) && overlap(R1.y1, R1.y2, R2.y1, R2.y2)) return 1;
	if (between(R2.x1, R1.x1, R2.x2) && overlap(R1.y1, R1.y2, R2.y1, R2.y2)) return 1;
	if (between(R2.x1, R1.x2, R2.x2) && overlap(R1.y1, R1.y2, R2.y1, R2.y2)) return 1;
	if (between(R1.y1, R2.y1, R1.y2) && overlap(R1.x1, R1.x2, R2.x1, R2.x2)) return 1;
	if (between(R1.y1, R2.y2, R1.y2) && overlap(R1.x1, R1.x2, R2.x1, R2.x2)) return 1;
	if (between(R2.y1, R1.y1, R2.y2) && overlap(R1.x1, R1.x2, R2.x1, R2.x2)) return 1;
	if (between(R2.y1, R1.y2, R2.y2) && overlap(R1.x1, R1.x2, R2.x1, R2.x2)) return 1;
	if (R1.x2 + 1 == R2.x1 && R2.y2 + 1 == R1.y1) return 1;
	if (R2.x2 + 1 == R1.x1 && R1.y2 + 1 == R2.y1) return 1;
	return 0;
}

int main () {
  int number_of_tests;
  scanf("%d", &number_of_tests);
  REP (test_number, number_of_tests) {
    printf("Case #%d: ", test_number+1);
    scanf("%d", &N);
		REP (i, N) father[i] = -1;
		REP (i, N) scanf("%d %d %d %d", &rs[i].x1, &rs[i].y1, &rs[i].x2, &rs[i].y2);
		REP (i, N) REP (j, i) if (touch(rs[i], rs[j])) join(i,j);
		REP (i, N) find(i);
		int best = -1;
    REP (i, N) {
			int hx = -2;
			int hy = -2;
			int ls = 20000000;
			REP (j, N) if (i == j || father[j] == i) {
				hx = max(hx, rs[j].x2);
				hy = max(hy, rs[j].y2);
				ls = min(ls, rs[j].x1 + rs[j].y1);
			}
			best = max(best, hx+hy-ls+1);
		}
		printf("%d\n", best);
  }
  return 0;
}

