// another fine solution by misof
// #includes {{{
#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define SIZE(t) ((int)((t).size()))
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

double getArea(const vector< pair<int,int> > L, double xmax) {
    double answer = 0.;
    for (int i=1; i<SIZE(L); ++i) {
        if (xmax < L[i].first) {
            double ymax = L[i-1].second + ((L[i].second - L[i-1].second)*1.)*(xmax - L[i-1].first)/(L[i].first-L[i-1].first);
            answer += (0.5*(xmax - L[i-1].first))*(ymax + L[i-1].second);
            return answer;
        } else {
            answer += (0.5*(L[i].first - L[i-1].first))*(L[i].second + L[i-1].second);
        }
    }
    return answer;
}

int main() {
    int T;
    cin >> T;
    FOR(t,1,T) {
        int W, L, U, G;
        cin >> W >> L >> U >> G;
        vector< pair<int,int> > lower, upper;
        REP(l,L) { int x,y; cin >> x >> y; lower.push_back(make_pair(x,y+1047)); }
        REP(u,U) { int x,y; cin >> x >> y; upper.push_back(make_pair(x,y+1047)); }
        double totalArea = getArea(upper,W) - getArea(lower,W);
        printf("Case #%d:\n",t);
        FOR(g,1,G-1) {
            double reqArea = (totalArea * g) / G;
            double lo = 0, hi = W;
            REP(loop,1000) {
                double med = (lo+hi)/2;
                double curArea = getArea(upper,med) - getArea(lower,med);
                if (curArea < reqArea) lo=med; else hi=med;
            }
            printf("%.12f\n",lo);
        }
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
