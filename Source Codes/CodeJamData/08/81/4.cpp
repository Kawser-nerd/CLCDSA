#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <cstdlib>
#include <cmath>
#include <list>

using namespace std;

#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),a.end()
#define SORT(a) sort(ALL(a))
#define UNIQUE(a) SORT(a),(a).resize(unique(ALL(a))-a.begin())
#define REVERSE(a) reverse(ALL(a))
#define SZ(a) ((int) a.size())
#define pb push_back

#define VAR(a,b) __typeof(b) a=(b)
#define FORE(it,a) for(VAR(it,(a).begin());it!=(a).end();it++)
#define X first
#define Y second
#define DEBUG(x) cout << #x << " = " << x << endl;

#define INF 1000000000

typedef vector <int> VI;
typedef vector <VI> VVI;
typedef pair <int,int> PII;
typedef vector <PII> VPII;

typedef long double cfloat;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int t;
    cin >> t;
    REP (tt, t)
    {
        
        cfloat x1, y1, x2, y2, x3, y3;
        cfloat xx1, yy1, xx2, yy2, xx3, yy3;
        
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        cin >> xx1 >> yy1 >> xx2 >> yy2 >> xx3 >> yy3;
        
        cfloat la = hypotl (x2-x1, y2-y1);
        cfloat lla = hypotl (xx2-xx1, yy2-yy1);
        
        cfloat coef = lla / la;
        //cout << coef << endl;
        
        cfloat phi1 = atan2 (y2-y1, x2-x1);
        cfloat phi2 = atan2 (yy2-yy1, xx2-xx1);
        
        cfloat ang = phi2-phi1;
        //cout << phi1 << endl;        
        
        cfloat mox = xx1-x1;
        cfloat moy = yy1-y1;
        
        cfloat x = x1;
        cfloat y = y1;
        
        cfloat an = 0;
        cfloat co = 1;
        
        REP (i, 10000000)
        {
            cfloat nmox = (mox*cos(an)-moy*sin(an))*co;
            cfloat nmoy = (mox*sin(an)+moy*cos(an))*co;
            an+=ang;
            
            x+=nmox;
            y+=nmoy;
            
            //cout << x <<  " " << y << endl;
            
            co*=coef;
        }
        
        printf ("Case #%d: %.6lf %.6lf\n",  tt+1, (double)x, (double)y);
    }

	return 0;
}
