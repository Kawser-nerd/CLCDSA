// another fine solution by misof
// #includes {{{
#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
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
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

int T,A,M,V;

inline int fix(int n) { return (n<0) ? 0 : (n>V) ? V : n; }

int main() {
    cin >> T;
    FOR(t,1,T) {
        cin >> A >> M >> V;
        vector<double> C(V+1,0);
        C[V]=1;
        REP(loop,10000) {
            FOR(n,1,V-1) {
                FOR(b,1,min(n,M)) {
                    int curbet = b;
                    int sumbet = b;
                    double loss = 0.5;
                    FOR(k,1,100) {
                        C[n]=max( C[n], loss * C[fix(n-sumbet)] + (1-loss)*C[fix(n+b)] );
                        loss *= 0.5;
                        curbet *= 2;
                        sumbet += curbet;
                        if (curbet > M) break;
                    }
                }
            }
        }
        int maxb = 1;
        FOR(b,1,min(A,M)) {
            int curbet = b;
            int sumbet = b;
            double loss = 0.5;
            FOR(k,1,100) {
                if (abs(C[A] - (loss * C[fix(A-sumbet)] + (1-loss)*C[fix(A+b)]) )<1e-9) maxb=b;
                loss *= 0.5;
                curbet *= 2;
                sumbet += curbet;
                if (curbet > M) break;
            }
        }
        printf("Case #%d: %.9f %d\n",t,C[A],maxb);
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
