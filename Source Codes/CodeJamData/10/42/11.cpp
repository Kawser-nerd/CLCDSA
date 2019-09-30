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

#define INFTY 200000000000LL

LL price[1<<11];
LL dyn[12][1<<12];
int P;

inline int lewy(int i) {return 2*i;}
inline int prawy(int i) {return 2*i + 1;}

int main () {
  int number_of_tests;
  scanf("%d", &number_of_tests);
  REP (test_number, number_of_tests) {
    printf("Case #%d: ", test_number+1);
		scanf("%d", &P);
		REP (i, P+1) REP (m, 1<<(P+1)) dyn[i][m] = INFTY;
    REP (i, 1<<P) {
			int m;
			scanf("%d", &m);
			m = P-m;
	//		printf("READ %d\n", m);
			for (int j = m; j <= P; j++) dyn[j][(1<<(P+1)) - (i+1)] = 0LL;
		}
		REP (i, (1<<P) - 1) {
			LL pr;
			scanf("%lld", &pr);
//			printf("READ %d\n", pr);
			price[(1<<P)-(i+1)] = pr;
		}
    for (int m = (1<<P) - 1; m >= 1; m--) REP (i, P+1) {
			dyn[i][m] = dyn[i][lewy(m)] + dyn[i][prawy(m)];
			if (i != P) dyn[i][m] = min(dyn[i][m], dyn[i+1][lewy(m)] + dyn[i+1][prawy(m)] + price[m]);
		}
		printf("%lld\n", dyn[0][1]);
  }
  return 0;
}

