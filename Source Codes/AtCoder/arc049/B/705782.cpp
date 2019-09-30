#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iomanip>

typedef long long ll;
#define rep(i, b) for(int i = 0; i < b; i++)
#define repi(i, a, b) for(int i = a; i < b; i++)
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define MAX_V 1001
#define MAX_E 401
#define MOD 1000000007
#define EPS 1e-7
#define INF INT_MAX
#define PI  3.14159265358979323846264338327950288
inline ll toll(std::string s) { ll v; std::istringstream sin(s); sin >> v; return v; }
template<class T> inline std::string toString(T x) { std::ostringstream sout; sout << x; return sout.str(); }
using namespace std;
typedef pair<ll, ll> pii;

struct xyc{
    double x,y,c;
};

ll N;
vector<xyc> XYC;

bool check(double mid)
{
    rep(i,N)
    {
        repi(j,i+1,N)
        {
            double Y = abs(XYC[i].y-XYC[j].y);
            if (Y > mid/XYC[i].c + mid/XYC[j].c)
            {
                return false;
            }
            double X = abs(XYC[i].x-XYC[j].x);
            if (X > mid/XYC[i].c + mid/XYC[j].c)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    cin >> N;
    XYC.resize(N);
    
    rep(i,N)
    {
        cin >> XYC[i].x >> XYC[i].y >> XYC[i].c;
    }
    
    double low = 0,high = INF;
    double ans = INF;
    while(high - low > 0.000001)
    {
        double mid = (high + low)/2;
        
        if(check(mid) == true)
        {
            high = mid;
            ans = min(mid,ans);
        }else{
            low = mid;
        }
    }
    
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}