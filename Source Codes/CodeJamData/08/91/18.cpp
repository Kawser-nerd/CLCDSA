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


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int t;
    cin >> t;
    
    FOR (tt, 1, t+1)
    {
        cout << "Case #"<<tt << ": ";
        
        int n;
        cin >> n;
        VI a(n), b(n), c(n);
        
        REP (i, n)
            cin >> a[i] >> b[i] >> c[i];
        int res = 0;
            
        REP (x, 10001) 
        {
            VI d(10002);
            REP (i, n)
            {
                if (a[i]<=x)
                {
                   int y1 = b[i];
                   int y2 = 10000-x-c[i];
                   if (y2>=y1)
                   {
                              d[y1]++;
                              d[y2+1]--;
                   }
                }
            }
            int r = 0;
            REP (i, d.size ())
            {
                r += d[i];
                res >?= r;
            } 
        }
        cout << res << endl;
    }


	return 0;
}
