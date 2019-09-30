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

const int N = 110;

int t[N][N][3];
char txt[N];

int licz(int lit, int a,int b){
	if (a > b) return 0;

	int &res = t[a][b][lit];
	if (res >= 0) return res;
	res = 3 * N;

	if (txt[a] - 'A' == lit) res = licz(lit, a+1,b);
	else {
		FOR(i,a+1,b) res = min(res, licz(lit,a,i-1) + licz(lit,i,b));

		lit = txt[a] - 'A';
		res = min(res, 1 + licz(lit, a+1,b));
	}
	return res;
}


int main(int argc, char **argv){
  int testy;
  scanf("%d",&testy);
  int numer=0;
  while (testy--){
	  ++numer;
	  scanf("%s",txt);
	  int n = strlen(txt);
	  int res = 3*n;
	  FOR(a,0,n-1) FOR(b,a,n-1) REP(lit,3) t[a][b][lit] = -1;
	  REP(lit,3) res = min(res, licz(lit, 0, n-1) + 1);


	if (argc == 3 && numer % atoi(argv[1]) != atoi(argv[2])){
		continue;
	}
    printf("Case #%d: ",numer);
	printf("%d\n", 2*res + n);
    fflush(stdout);
  }
  return 0;
}
