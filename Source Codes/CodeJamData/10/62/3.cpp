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

const int N = 1100;

int kraw[N][N];
int para[N][2];

void dodaj(int a, int b){
	kraw[a][b] = kraw[b][a] = 0;
}

int main(int argc, char **argv){
  int testy;
  scanf("%d",&testy);
  int numer=0;
  while (testy--){
	  int n;
	  scanf("%d",&n);
	  REP(i,n) REP(j,n) kraw[i][j] = -1;
	  dodaj(0,1); dodaj(0,2); dodaj(1,2);
	  FOR(i,3,n-1){
		  int a,b;
		  scanf("%d %d",&a,&b);
		  a--; b--;
		  para[i][0] = a; para[i][1] = b;
		  dodaj(i,a);
		  dodaj(i,b);
	  }
	  int res = 3;
	  FORD(i,n-1,3){
		  int a = para[i][0];
		  int b = para[i][1];
		  assert(kraw[i][a] >= 0 && kraw[i][a] == kraw[a][i]);
		  assert(kraw[i][b] >= 0 && kraw[i][b] == kraw[b][i]);
		  assert(kraw[a][b] >= 0 && kraw[b][a] == kraw[a][b]);
		  res = max(res, kraw[i][a] + kraw[i][b] + kraw[a][b] + 3);
		  int x = max(kraw[a][b], kraw[a][i] + 1 + kraw[i][b]);
		  kraw[a][b] = kraw[b][a] = x;
	  }
	  res = max(res, kraw[0][1] + kraw[1][2] + kraw[2][0] + 3);

	  ++numer;
	  if (argc == 3 && numer % atoi(argv[1]) != atoi(argv[2])){
		  continue;
	  }
	  printf("Case #%d: ",numer);
	  printf("%d\n", res);
	  fflush(stdout);
  }
  return 0;
}
