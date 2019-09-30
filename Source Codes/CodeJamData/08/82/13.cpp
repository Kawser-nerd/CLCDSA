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
typedef pair<int,int> PII;

const int inf = 999999999;

/////////////////////////////////////////////////////////////////////////////////////////////////

void solve () {
  int N;
  cin>>N;

  int numcol=0;
  map<string,int> colid;
  vector<vector<PII> > offers(N);
  
  REP(i,N) {
    string col; int fr,to;
    cin>>col>>fr>>to;
    if (!colid.count(col)) colid[col] = numcol++;
    offers[colid[col]].PB(make_pair(fr,to));
  }

  int res=INT_MAX;
  
  REP(a,numcol) REP(b,a+1) REP(c,b+1) {
    vector<PII> pos;
    REP(i,offers[a].SZ) pos.PB(offers[a][i]);
    REP(i,offers[b].SZ) pos.PB(offers[b][i]);
    REP(i,offers[c].SZ) pos.PB(offers[c][i]);

    sort(pos.begin(),pos.end());

    int to=1,i=0,n=0;
    while(to!=10001) {
      int next=-1;
      if (i==pos.SZ || pos[i].first>to) break;
      while (i<pos.SZ && pos[i].first <= to) next = max(next, pos[i++].second);
      if (next==-1) break;
      to=next+1;
      n++;
      if (to==10001) res = min(res, n);
    }
  }

  if (res==INT_MAX)
    cout<<"IMPOSSIBLE";
  else
    cout<<res;  
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
