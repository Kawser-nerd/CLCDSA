#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <numeric>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define REP(i,n) FOR(i,0,n)

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)

#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 1000000000
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;

#define TEST_NAME "B-large"

const double eps=1e-9;
#define SQR(x) ((x)*(x))

int main() {
     freopen(TEST_NAME ".in","r",stdin);
     freopen(TEST_NAME ".out","w",stdout);
     int n,test;
	
     for(cin>>n,test=1;test<=n;++test) {
          double val[6]={0};
          double &x=val[0],&y=val[1],&z=val[2],&vx=val[3],&vy=val[4],&vz=val[5];
          double d,t;
          int n;
          cin>>n;
          REP(i,n)REP(k,6) {cin>>t;val[k]+=t;}          
          REP(k,6)val[k]/=n;
          if(SQR(vx)+SQR(vy)+SQR(vz)<eps) {
               t=0.0;
               d=sqrt(SQR(x)+SQR(y)+SQR(z));
          }
          else {
               t=-(x*vx+y*vy+z*vz)/(SQR(vx)+SQR(vy)+SQR(vz));
               if(t<0.0)t=0.0;
               d=sqrt(SQR(x+t*vx)+SQR(y+t*vy)+SQR(z+t*vz));
          }
          printf("Case #%d: %.10lf %.10lf\n",test,d,t);
     }
	
     fprintf(stderr,"running time=%.3lf\n",clock()/(double)CLOCKS_PER_SEC);
     return 0;
} 
