using namespace std;
 
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
 
#define PB push_back
#define SZ size()
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define UNIQUE(x) x.erase(unique(ALL(x)),x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define REPD(x, hi) for (int x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (int x=((hi)-1); x>=(lo); x--)
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef long long LL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;

const int inf = 999999999;

/////////////////////////////////////////////////////////////////////////////////////////////////

VVI cache;
int N,P;
VI x;

int go (int fr, int to) {

  int &res = cache[fr][to];
  if (res!=-1) return res;

  if (to-fr<=1) return 0;
  
  res=inf;
  
  FOR(i,fr+1,to)
    res <?= x[to]-x[fr]-2 + go(fr,i) + go(i,to);

  return res;
}

void solve () {

  cin>>P>>N;

  x=VI(N);
  REP(i,N) cin>>x[i];
  x.PB(0);
  x.PB(P+1);
  N+=2;
  sort(x.begin(),x.end());
    
  cache = VVI(N, VI(N, -1));
  cout<<go(0,N-1);  
}

int main () {

  int runs;
  scanf ("%i\n",&runs);

  for (int run=1; run<=runs; run++) {
    printf ("Case #%i: ",run);
    solve();
    printf ("\n");
  }

  return 0;
}
