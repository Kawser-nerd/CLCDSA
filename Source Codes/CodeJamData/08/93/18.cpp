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
#define SZ(a) ((int) a.size())
#define pb push_back

#define VAR(a,b) __typeof(b) a=(b)
#define FORE(it,a) for(VAR(it,(a).begin());it!=(a).end();it++)
#define X first
#define Y second

#define INF 1000000000

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long ll;

int n, m;
                
VVI a;
VVI b;

int  get (int x, int y)
{
    if (x<0 || x>=n || y<0 || y>=m)
       return 0;
    return b[x][y];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    FOR (tt, 1, t+1)
    {
        cout << "Case #" << tt<< ": ";
        
        cin >> n >> m;
        a = VVI(n, VI (m));
        b = VVI (n, VI (m));
        
        REP (i, n)
            REP (j, m)
                cin >> a[i][j];
        
        int c = n*m;
        
        int res = 0;
        
        REP (i, 1<<c)
        {
            int cc = 0;
            REP (j, n)
                REP (k, m)
                {
                    if (i & (1<<cc))
                       b[j][k] = 1;
                    else
                        b[j][k] = 0;
                    cc++;
                }
            int r = 0;
            
         
            
            REP (x, n)
                REP (y, m)
                {
                    int cc = 0;
                    FOR (dx, -1, 2)
                        FOR (dy, -1, 2)
                            cc += get(x+dx, y+dy);
                    if (cc!=a[x][y])
                       goto next;
                }
                
/*            REP (x, n)
            {
                REP (y, m)
                    cout << b [x][y] ;
                cout << endl;
            }
  */          
            REP (j, m)
                r += b[n/2][j];
                
            res >?= r;
            
            
            next:;
        }
        
        cout << res << endl;
        
        
    }

	return 0;
}
