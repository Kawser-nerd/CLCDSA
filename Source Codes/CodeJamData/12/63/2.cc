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

int N;
vector<long long> X, Y;
vector<char> C;

#define INF 3000000000000000LL
#define RAD 4

inline bool check(long long x, long long y) {
    //cout << "check " << x << " " << y << endl;
    REP(n,N) {
        long long d = max( abs( x-X[n] ), abs( y-Y[n] ) );
        if (d%2==1) if (C[n]=='.') return false;
        if (d%2==0) if (C[n]=='#') return false;
    }
    return true;
}

inline void update(bool &found, long long &ansx, long long &ansy, long long x, long long y) {
    if (!found) { found = true; ansx = x; ansy = y; return; }
    if (abs(x)+abs(y) > abs(ansx)+abs(ansy)) return;
    if (abs(x)+abs(y) < abs(ansx)+abs(ansy)) { ansx=x; ansy=y; return; }
    if (x < ansx) return;
    if (x > ansx) { ansx=x; ansy=y; return; }
    if (y < ansy) return;
    if (y > ansy) { ansx=x; ansy=y; return; }
}

int main() {
    int T; cin >> T;
    FOR(t,1,T) {
        cin >> N;
        X.clear(); X.resize(N);
        Y.clear(); Y.resize(N);
        C.clear(); C.resize(N);
        REP(n,N) {scanf(" %lld %lld %c",&X[n],&Y[n],&C[n]);}

        set<long long> sumset, diffset;
        REP(n,N) { sumset.insert(Y[n]+X[n]); diffset.insert(Y[n]-X[n]); }
        sumset.insert(0);
        diffset.insert(0);

        vector<long long> sums(sumset.begin(),sumset.end());
        vector<long long> diffs(diffset.begin(),diffset.end());
        
        bool found = false;
        long long ansx=0, ansy=0;

        int SS = SIZE(sums), DS = SIZE(diffs);
        for (int si=0; si<SS; ++si) for (int di=0; di<DS; ++di) {
            long long s0 = sums[si], d0 = diffs[di];
            for (long long s=s0-RAD; s<=s0+RAD; ++s) {
                for (long long d=d0-RAD; d<=d0+RAD; ++d) {
                    if (abs(s)%2 != abs(d)%2) continue;
                    long long y = (s+d)/2;
                    long long x = s-y;
                    if (check(x,y)) update(found,ansx,ansy,x,y);
                }
            }
        }

        for (int si=0; si<SS; ++si) {
            long long s0 = sums[si];
            for (long long s=s0-RAD; s<=s0+RAD; ++s) {
                for (long long x=-RAD; x<=+RAD; ++x) {
                    long long y = s-x;
                    if (check(x,y)) update(found,ansx,ansy,x,y);
                    if (check(y,x)) update(found,ansx,ansy,y,x);
                }
            }
        }

        for (int di=0; di<DS; ++di) {
            long long d0 = diffs[di];
            for (long long d=d0-RAD; d<=d0+RAD; ++d) {
                for (long long x=-RAD; x<=+RAD; ++x) {
                    long long y = d+x;
                    if (check(x,y)) update(found,ansx,ansy,x,y);
                }
                for (long long y=-RAD; y<=+RAD; ++y) {
                    long long x = y-d;
                    if (check(x,y)) update(found,ansx,ansy,x,y);
                }
            }
        }

        if (found) {
            printf("Case #%d: %lld %lld\n",t,ansx,ansy);
        } else {
            printf("Case #%d: Too damaged\n",t);
        }
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
