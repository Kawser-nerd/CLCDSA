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

double len(double x, double y, double z) { return sqrt(x*x+y*y+z*z); }

void solve () {

  double x=0,y=0,z=0,vx=0,vy=0,vz=0;
  int N;
  cin>>N;
  REP(i,N) {
    double X,Y,Z,VX,VY,VZ;
    cin>>X>>Y>>Z>>VX>>VY>>VZ;
    x+=X/N;
    y+=Y/N;
    z+=Z/N;
    vx+=VX/N;
    vy+=VY/N;
    vz+=VZ/N;
  }

  double ax = y*vz-z*vy;
  double ay = z*vx-x*vz;
  double az = x*vy-y*vx;

  if (fabs(vx)<1e-9 && fabs(vy)<1e-9 && fabs(vz)<1e-9) {
    cout<<len(x,y,z)<<" "<<0;
  }
  else {
    double d = len(ax,ay,az) / len(vx,vy,vz);
    double t = sqrt(len(x,y,z)*len(x,y,z)-d*d) / len(vx,vy,vz);

    if (len(x+t*vx,y+t*vy,z+t*vz) - d > 1e-9) {
      t=0;
      d=len(x,y,z);
    }
  
    cout<<d<<" "<<t;
  }
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
