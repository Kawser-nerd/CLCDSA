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


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int tt;
    cin >> tt;
    REP (t, tt)
    {
        cout << "Case #"<<(t+1)<<": "; 
        
        int n;
        cin >> n;
        
        int m = 0;
        map <string, int> M;
        vector <VPII> a;
        REP (i, n)
        {
            string color;
            PII p;
            cin >> color >> p.X >> p.Y;
            
            if (!M.count (color))
            {
               M[color] = m++;
               a.pb (VPII ());
            }  
            a[M[color]].pb (p);
        }
        
        while (a.size ()<3)
              a.pb (a[0]);
        n = a.size ();
        
        REP (i, n)
        {
            SORT (a[i]);
        }
        
        int i[3];
        
        int res = INF;
        for (i[0]=0; i[0]<n; i[0]++)
        for (i[1]=i[0]+1; i[1]<n; i[1]++)
        for (i[2]=i[1]+1; i[2]<n; i[2]++)
        {
            int d[3];
        
            memset (d, 0, sizeof (d));
            int x = 0;
            int r = 0;       
            
            while (x<10000)
            {
                  int y = x;
                  REP (j, 3)
                      while (d[j]<a[i[j]].size () && a[i[j]][d[j]].X<=x+1)
                      {
                            y >?= a[i[j]][d[j]].Y;
                            d[j]++;
                      }
                  
                  if (y==x)
                     goto next;
                  x = y;
                  r++;
            }
            
            res<?=r;
           
            next:;
        }
        
        if (res<INF)
           cout << res << endl;
        else
            cout << "IMPOSSIBLE" << endl;
    }

	return 0;
}
