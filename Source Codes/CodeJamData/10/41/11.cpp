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

int dim[120][120];
int K;
int MN;

int dist (int cx, int cy) {
	return abs((K-1) - cx) + abs((K-1) - cy);
}

int nok(int d, int x, int y) {
	if (x < 0 || x > MN || y < 0 || y > MN || dim[x][y] == 10 || d == 10 || dim[x][y] == d) return 1;
	return 0;
}

int bounce (int cx, int cy) {
	for (int x = 0; x <= MN; x++) for (int y = 0; y <= MN; y++) {
		if (!nok(dim[x][y], 2*cx-x, y)) return 0;
		if (!nok(dim[x][y], 2*cx-x, 2*cy-y)) return 0;
		if (!nok(dim[x][y], x, 2*cy - y)) return 0;
	}
	return 1;
}

int main () {
  int number_of_tests;
  scanf("%d", &number_of_tests);
  REP (test_number, number_of_tests) {
    printf("Case #%d: ", test_number+1);
    REP (i, 120) REP (j, 120) dim[i][j] = 10;
		scanf("%d", &K);
		int s = K;
		for (int l = 1; l <= K; l++) {
			int pos = s-l;
			for (int p = 1; p <= l; p++) {
				int re;
				scanf("%d", &re);
				dim[pos][l-1] = re;
				pos += 2;
			}
		}
		for (int row = K; row < 2 * K - 1; row++) {
			int l = 2 * K - (row + 1);
			int pos = row - (K-1);
			for (int p = 1; p <= l; p++) {
				int re;
				scanf("%d", &re);
				dim[pos][row] = re;
				pos += 2;
			}
		}
/*    REP (i, 2*K) {
			REP (j, 2*K) if (dim[j][i] == 10) printf("-"); else printf("%d", dim[j][i]);
			printf("\n");
		}*/
		MN = 2*K-2;
		int best = 2000;
		for (int cx = 0; cx <= MN; cx++) for (int cy = 0; cy <= MN; cy++) 
			if (dist(cx,cy) < best) if (bounce(cx, cy)) best = dist(cx,cy);
		printf("%d\n", (K+best)*(K+best) - K*K);
  }
  return 0;
}

