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

void solve () {

  int x1,y1,x2,y2,x3,y3;
  int X1,Y1,X2,Y2,X3,Y3;

  cin>>X1>>Y1>>X2>>Y2>>X3>>Y3;
  cin>>x1>>y1>>x2>>y2>>x3>>y3;

  int OX1 = X1;
  int OY1 = Y1;

  x1-=OX1; y1-=OY1;
  x2-=OX1; y2-=OY1;
  x3-=OX1; y3-=OY1;
  X1-=OX1; Y1-=OY1;
  X2-=OX1; Y2-=OY1;
  X3-=OX1; Y3-=OY1;
  
  int A1 = abs((X2-X1)*(Y3-Y1) - (X3-X1)*(Y2-Y1));
  int a1 = abs((x2-x1)*(y3-y1) - (x3-x1)*(y2-y1));

  double s = sqrt(1.0*a1/A1);

  double tx = x1-X1;
  double ty = y1-Y1;

  double th1 = atan2(Y2-Y1, X2-X1);
  double th2 = atan2(y2-y1, x2-x1);

  double theta = th2-th1;

  //  printf ("th1=%lf th2=%lf\n",th1,th2);
  //  printf ("%lf %lf (%lf,%lf)\n",s,theta,tx,ty);
  
  double A = tx - ty*s*sin(theta)/(1-s*cos(theta));
  double B = 1 - s*cos(theta) + s*s*sin(theta)*sin(theta) / (1-s*cos(theta));

  //  printf ("%lf %lf\n",A,B);
  
  double x = A/B;
  double y = (ty + s*x*sin(theta)) / (1 - s*cos(theta));
  x += OX1;
  y += OY1;
  
  printf ("%.9lf %.9lf",x,y);
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
