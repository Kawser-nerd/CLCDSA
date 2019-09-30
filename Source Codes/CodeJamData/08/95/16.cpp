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

int r [1<<15][16][16];
int n, m;
vector <string> a;

char get (int x, int y)
{
     if (x<0 || x>=n || y<0 || y>=m)
        return '.';
     return a[x][y];
 }

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int t;
    cin >> t;
    FOR (tt, 1, t+1)
    {
        cout << "Case #" << tt << ": ";
        
        cin >> n >> m;
        
        a = vector <string> (n);
        
        REP (i, n)
            cin >> a[i];
        
        REP (i, 1<<m)
            REP (x, n+1)
                REP (y, m)
                    r[i][x][y] = -INF;
        
        r[0][0][0] = 0;
        
        REP (x, n)
            REP (y, m)
            {
                int xx = x;
                int yy = y+1;
                if (yy == m)
                {
                    yy = 0;
                    xx++;
                }
                
                REP (i, 1<<m)
                    if (r[i][x][y]>-INF)
                    {
                       if (get (x, y)=='.' || get(x,y)=='?')
                       {
                          int ii = i;
                          if (ii & (1<<y))
                             ii ^= 1<<y;
                          r[ii][xx][yy] >?= r[i][x][y];
                       }
                       if (get(x,y ) =='#' || get(x, y) == '?')
                       {
                          int ii = i | (1<<y);
                          int add = 4;
                          if (i & (1<<y))
                             add-=2;
                          if (y && (i & (1<<(y-1)))) 
                             add-=2;
                          
                          r[ii][xx][yy]>?= r[i][x][y]+add;
                       }
                    }
                    
            }
        int res = -INF;
		REP (i, 1<<m)
		    res>?= r[i][n][0];
		    
        cout << res << endl;
    }


	return 0;
}
