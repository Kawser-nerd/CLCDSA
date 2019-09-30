#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cassert>
#include <complex>
using namespace std;
typedef long long ll;
typedef complex<double> P;
const double EPS=1e-8, PI=acos(-1.0);

#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define FOREQ(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

#define SZ(v) (int)((v).size())
#define MEMSET(v,h) memset((v),(h),sizeof(v))
#define FIND(m,w) ((m).find(w)!=(m).end())

#define EQ(a,b) (abs((a)-(b)) < EPS)

double dot(P a,P b) { return real(conj(a)*b); }
double cross(P a,P b) { return imag(conj(a)*b); }
int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if (cross(b, c) > +EPS)   return +1;    // counter clockwise
    if (cross(b, c) < -EPS)   return -1;    // clockwise
    if (dot(b, c) < 0)     return +2;       // c--a--b on line
    if (norm(b) < norm(c)) return -2;       // a--b--c on line
    return 0;                               // a--c--b
}

P intersection_ll(P s0, P s1, P t0, P t1) {
    P sv=s1-s0, tv=t1-t0;
    assert(!EQ(cross(sv, tv),0.0));
    return s0 + sv * cross(tv, t0-s0) / cross(tv, sv);
}

#define curr(g,i) g[i]
#define next(g,i) g[(i+1)%SZ(g)]
double area2(vector<P> &g) {
    double A = 0;
    REP(j,SZ(g)) 
        A += cross(curr(g,j), next(g,j));
    return A;
}

P getp() { double x,y; scanf("%lf%lf", &x, &y); return P(x,y); }

P upper[120], lower[120];

void solve() {
    double W; int L,U,G; scanf("%lf%d%d%d", &W, &L, &U, &G);
    REP(i, L) lower[i] = getp();
    REP(i, U) upper[i] = getp();
    vector<P> vg;
    REP(i, U) vg.push_back(upper[i]);
    reverse(vg.begin(), vg.end());
    REP(i, L) vg.push_back(lower[i]);

    double alla = area2(vg) / 2.0;

    //cout<<"#"<<alla<<endl;

    REP(itr, G-1) {
        double sz = alla * (itr+1) / G;
            // bin search
        double lo = 0, hi = W;
        REP(itr2, 60) {
            double x = (lo+hi) / 2.0;
                // get area
            vg.clear();
            vg.push_back(upper[0]);
            FOR(i, 1, U) {
                if (x < upper[i].real()) { vg.push_back( intersection_ll(upper[i-1], upper[i], P(x, 0), P(x, 1)) ); break; }
                else vg.push_back(upper[i]);
            }
            reverse(vg.begin(), vg.end());
            vg.push_back(lower[0]);
            FOR(i, 1, L) {
                if (x < lower[i].real()) { vg.push_back( intersection_ll(lower[i-1], lower[i], P(x, 0), P(x, 1)) ); break; }
                else vg.push_back(lower[i]);
            }
            double temp = area2(vg) / 2.0;
            if (temp < sz) lo = x;
            else hi = x;
        }
        printf("%.12f\n", lo);
    }
}

int main()
{
    int T; scanf("%d", &T);
    while (T--) {
        static int test = 1;
        printf("Case #%d:\n",test++);
        solve();
    }
}

