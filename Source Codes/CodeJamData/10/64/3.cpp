#include <cassert>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <numeric>
#include <cmath>
using namespace std;

typedef vector <int > VI;
typedef vector < VI > VVI;
typedef long long LL;
typedef vector < LL > VLL;
typedef vector < double > VD;
typedef vector < string > VS;
typedef pair<int,int> PII;
typedef vector <PII> VPII;
typedef istringstream ISS;

#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for (int i=0; i<(n); ++i)
#define FOR(var,pocz,koniec) for (int var=(pocz); var<=(koniec); ++var)
#define FORD(var,pocz,koniec) for (int var=(pocz); var>=(koniec); --var)
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define PB push_back
#define PF push_front
#define MP(a,b) make_pair(a,b)
#define ST first
#define ND second
#define SIZE(x) (int)(x).size()

inline int between(LL a, LL b, LL c){
  return a >= b && a <= c;
}

const LL INF = 1000LL * 1000 * 1000 * 1000 * 1000 * 1001;
const int K = 22;
const int S = 17;

set<LL> t[40][40];

inline LL ABS(LL x){
	return x >= 0 ? x : -x;
}

vector<set<LL> > licz(vector<LL> pozycje, LL granica, int odwroc){
	pozycje.PB(granica);
	if (odwroc) FOREACH(it, pozycje) *it = -*it;

	sort(ALL(pozycje));
	int n = SIZE(pozycje);

	REP(i,n) FOR(j,0,K+1) t[i][j].clear();
	t[0][1].insert(0);
	/*
	printf("n=%d, granica=%lld\n", n, granica);
	FOREACH(it, pozycje) printf("%lld ", *it);
	puts("");
	*/
	FOR(i,1,n-1) FOR(j,1,K){
		//przelot
		LL foo = ABS(pozycje[i] - pozycje[i-1]) * j * 2;
		FOREACH(it, t[i-1][j]) t[i][j].insert(*it + foo);
		
		if (i != n-1){
			//powrot
			foo = ABS(pozycje[i] - pozycje[i-1]) * (j-1) * 2;
			FOREACH(it, t[i-1][j-1]) t[i][j].insert(*it + foo);

			foo = ABS(pozycje[i] - pozycje[i-1]) * (j+1) * 2;
			FOREACH(it, t[i-1][j+1]) t[i][j].insert(*it + foo);
		}

		/*
		printf("dla i=%d j=%d rozmiar=%d\n", i,j, SIZE(t[i][j]));
		FOREACH(it, t[i][j]) printf("%lld ", *it);
		puts("");
		*/
	}

	vector<set<LL > > res;
	FOR(ile_razy,1,K){
		res.PB(t[n-1][ile_razy]);
	}
	return res;
}

int main(int argc, char **argv){
  int testy;
  scanf("%d",&testy);
  int numer=0;
  while (testy--){
    int n;
	scanf("%d",&n);
	vector<LL> pozycje;
	REP(i,n){
		LL x;
		scanf("%lld",&x);
		x *= 2;
		pozycje.PB(x);
	}
	LL paliwo;
	scanf("%lld",&paliwo);
	paliwo *= 2;
	LL res = INF;

	sort(ALL(pozycje));

	vector<LL> lewe, prawe;
	REP(i, n) if (i < n/2) lewe.PB(pozycje[i]);
	else prawe.PB(pozycje[i]);
	assert(!lewe.empty());
	assert(!prawe.empty());
	LL granica = (lewe.back() + prawe[0]) / 2;

	vector<set<LL> > lewy_res = licz(lewe, granica, 0);
	vector<set<LL> > prawy_res = licz(prawe, granica, 1);

	assert(SIZE(lewy_res) == K && SIZE(prawy_res) == K && 2 * K > n+3);

	REP(i,K){
		FOREACH(it, lewy_res[i]) if (*it <= paliwo){
			set<LL>::iterator it2 = prawy_res[i].upper_bound(paliwo-*it);
			if (it2 != prawy_res[i].begin()){
				--it2;
				LL kand = *it + *it2;
				if (kand <= paliwo){
					if (res == INF || res < kand) res = kand;
				}
			}
		}
	}

    ++numer;
	if (argc == 3 && numer % atoi(argv[1]) != atoi(argv[2])){
		continue;
	}
    printf("Case #%d: ",numer);
	if (res == INF) puts("NO SOLUTION");
	else{
		assert(res % 2 == 0);
	   	printf("%lld\n", res / 2);
	}
    fflush(stdout);
  }
  return 0;
}
