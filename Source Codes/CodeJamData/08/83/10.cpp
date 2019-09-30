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
typedef vector<VVLL> VVVLL;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;

const int inf = 999999999;
const LL MOD = 1000000009;

/////////////////////////////////////////////////////////////////////////////////////////////////

int N,C;
VVLL cache;
VVI conn;

LL go (int n, int par, int n2) {

  //  printf ("%i(%i) %i\n",n,par,n2);

  if (n2>C) return 0;
  
  LL &res = cache[n][n2];
  if (res != -1) return res;

  int left = C-n2;
  if (par!=-1) left--;
  
  int childs = conn[n].SZ;
  if (par!=-1) childs--;

  if (childs > left) return res=0;

  res=1;
  REP(i,childs) res = (res * (left-i)) % MOD;
  int newn2 = childs-1;
  if (par!=-1) newn2++;

  //  printf ("ch=%i newn2=%i par=%i left=%i\n",childs,newn2,par,left);
  
  REP(ii,conn[n].SZ) {
    int i = conn[n][ii];
    if (i==par) continue;
    res = (res * go(i,n,newn2)) % MOD;
  }
  
  //  printf ("%i %i -> %lli\n",n,n2,res);
  return res;
}

void solve () {

  cin>>N>>C;

  conn=VVI(N);
  REP(i,N-1) {
    int a,b;
    cin>>a>>b;
    a--; b--;
    conn[a].PB(b);
    conn[b].PB(a);
  }

  cache=VVLL(N, VLL(N+1, -1));
  cout<<go(0,-1,0);    
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
