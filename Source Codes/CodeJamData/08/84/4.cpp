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
typedef pair <int, int> PII;
typedef vector <PII> VPII;

#define mod 30031

int a[1<<10];

int m;

VVI mul (VVI& a, VVI &b)
{
    VVI res (m, VI(m));
    
    REP (i, m)
        REP (j, m)
        {
            REP (k, m)
            {
                res[i][j] += a[i][k]*b[k][j];
                res[i][j] %= mod;
                
            }
            //res[i][j] %= mod;
        }
    return res;    
}

VVI pow (VVI &a, int p)
{
    if (p==1)
       return a;
    VVI res = pow (a, p/2);
    
    res = mul (res, res);
    if (p&1)
       res = mul (res, a);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int t;
    cin >> t;
    
    REP (tt, t)
    {
        cout << "Case #"<<(tt+1) << ": ";
        int n, k, p;
        cin >> n >> k >> p;
        
        memset (a, 0, sizeof (a));
        
        m = 0;
        
        REP (i, 1<<p)
        {
            int x = i;
            int c = 0;
            
            while (x)
            {
                  c+= x&1;
                  x>>=1;
            }
            if (c==k)
               a[i] = m++;
        }
        
        VVI ma(m, VI (m));
        REP (i, 1<<p)
            if (a[i] || i==(1<<k)-1)
            {
               // cout << i << endl;
                if (i&1)
                {
                    if (i&2)
                    {REP (j, p)
                        if (!(i& (2<<j)))
                        {
                           int v = (i>>1)|(1<<j);
                           //cout << "moving "  << v << endl;
                           ma[a[v]][a[i]]++;
                        }
                        }
                    else
                    {
                        int v = (i>>1)+1;
                        ma[a[v]][a[i]]++;
                    }
                }
                else
                    ma[a[i>>1]][a[i]] ++;
            }        
        /*REP (i, m)
        {
            REP (j, m)
                cout << ma[i][j] << " ";
            cout << endl;
        }*/
        
        
        
       /* FOR (pp, 1, 4)
        {
             VVI rma =  pow (ma, pp);
             REP (i, m)
             {
                REP (j, m)
                    cout << rma[i][j] << " ";
                cout << endl;
             }
        }*/
        int pp = n-k;
        
        VVI rma =  pow (ma, pp);
        

        
        cout << rma[0][0] << endl;
    }

	return 0;
}
