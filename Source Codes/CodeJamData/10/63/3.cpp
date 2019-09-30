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


int main(int argc, char **argv){
  int testy;
  scanf("%d",&testy);
  int numer=0;
  while (testy--){
	++numer;
	int k; LL c;
	scanf("%d %lld",&k,&c);
	LL res = 0;
	LL brakuje = k;
	LL i = 1;
	while (i <= c){
		assert(brakuje >= 0);
		LL biore = (brakuje + (i-1)) / i;
		res += biore;
		brakuje -= biore * i;
		//szukam takiego x, ze x * k 
		LL zapas = -brakuje;
		assert(zapas >= 0);
		LL przeskok = zapas/k + 1;
		brakuje += przeskok * k;
		assert(brakuje >= 0);
		i += przeskok;
	}


	if (argc == 3 && numer % atoi(argv[1]) != atoi(argv[2])){
		continue;
	}
    printf("Case #%d: ",numer);
	printf("%lld\n", res);
    fflush(stdout);
  }
  return 0;
}
