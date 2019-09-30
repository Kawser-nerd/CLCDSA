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
#include <cassert>
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

#define ALL(x) x.begin(),x.end()
#define REP(i,n) for (int i=0; i<(n); ++i)
#define FOR(var,pocz,koniec) for (int var=(pocz); var<=(koniec); ++var)
#define FORD(var,pocz,koniec) for (int var=(pocz); var>=(koniec); --var)
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define PB push_back
#define PF push_front
#define MP(a,b) make_pair(a,b)
#define ST first
#define ND second
#define SIZE(x) (int)x.size()

const int N = 11000;
int a[N], b[N];

int main(){
  int testy;
  scanf("%d",&testy);
  int numer=0;
  while (testy--){
    printf("Case #%d: ",++numer);
    int n;
    scanf("%d",&n);
    assert(n < N);
    REP(i,n) scanf("%d %d",a+i,b+i);
    int res = 0;
    REP(i,n) REP(j,i) res += ((a[i] < a[j]) ^ (b[i] < b[j]));
    printf("%d\n", res);
  }
  return 0;
}
