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

vector <string> a;

int d1[64][64];
int d2[64][64];

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
        a.resize (n);
        REP (i, n)
            cin >> a[i];
            
        REP (i, n)
            REP (j, m)
            {
                d1[i][j] = INF;
                d2[i][j] = INF;
            }
            
        d1[0][0] = 0;
        
        queue <PII> q;
        
        q.push (PII (0, 0));
        
        VPII d;
        d.pb (PII (-1, 0));
        d.pb (PII (1, 0));
        d.pb (PII (0, -1));
        d.pb (PII (0, 1));
    
        while (!q.empty ())
        {
              int x = q.front ().X;
              int y = q.front ().Y;
              q.pop();
              
              REP (dd, 4)
              {
                  int xx = x+d[dd].X;
                  int yy = y+d[dd].Y;
                  
                  if (get(xx,yy)!='.' && d1[xx][yy]>d1[x][y]+1)
                  {
                     d1[xx][yy]=d1[x][y]+1;
                     q.push (PII (xx, yy));
                  }
              }
        }
        
        bool two = false;
        
        int res = 0;
        
        int v;        
            
        REP (i, n)
            REP (j, m)
                if (i + j && a[i][j] == 'T')
                {
                      d2[i][j] = 0;
                        
                        queue <PII> q;
                        
                        q.push (PII (i, j));
                        
                    
                        while (!q.empty ())
                        {
                              int x = q.front ().X;
                              int y = q.front ().Y;
                              q.pop();
                              
                              REP (dd, 4)
                              {
                                  int xx = x+d[dd].X;
                                  int yy = y+d[dd].Y;
                                  
                                  if (get(xx,yy)!='.' && d2[xx][yy]>d2[x][y]+1)
                                  {
                                     d2[xx][yy]=d2[x][y]+1;
                                     q.push (PII (xx, yy));
                                  }
                              }
                        }
                        two = true;
                        v = d1[i][j];
                }
            
        if (two)    
        FOR (i, 0, v+1)
        {
            res += i - min (i, v-i);
        }

        REP (i, n)
            REP (j, m)
            if (a[i][j]!='.')
            {
                
                res += min (d1[i][j], d2[i][j]);
                
                next:;
            }
            
        cout << res << endl;
    }


	return 0;
}
