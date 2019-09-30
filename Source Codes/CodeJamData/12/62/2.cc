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
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

int N, K;
vector<int> A, B, C;
vector<double> P;
map<int,double> memo;

double skus(int big) {
    if (memo.count(big)) return memo[big];
    vector<double> used;
    used.insert( used.end(), P.begin(), P.begin()+big );
    used.insert( used.end(), P.end()-(K-big), P.end() );
    double awake = 1., asleep = 0., bad = 0.;
    for (int k=0; k<K; ++k) {
        double nawake = awake * used[k];
        double nasleep = (awake+asleep) * (1-used[k]);
        double nbad = bad + asleep * used[k];
        awake = nawake;
        asleep = nasleep;
        bad = nbad;
    }
    double good = 1-bad;
    memo[big] = good;
    return good;
}

int main(int argc, char **argv) {
    int ID; sscanf(argv[1],"%d",&ID);
    int tlo = 20*ID+1, thi = 20*(ID+1)+1;

    int T; scanf("%d ",&T);
    FOR(t,1,T) {
        memo.clear();
        scanf("%d ",&N);
        scanf("%d ",&K);
        A.clear(); A.resize(N);
        B.clear(); B.resize(N);
        C.clear(); C.resize(N);
        REP(n,N) {
            scanf("%d/%d %d ",&A[n],&B[n],&C[n]);
        }
        if (t<tlo || t>=thi) continue;
        P.clear();
        REP(n,N) REP(i,C[n]) P.push_back((1.*A[n])/B[n]);
        sort(P.begin(),P.end());
        reverse(P.begin(),P.end());
        double best = 0.;
        int biglo=0, bighi=K;
        while (bighi - biglo > 10) {
            int big1 = (biglo+biglo+bighi)/3;
            int big2 = (biglo+bighi+bighi+2)/3;
            double good1 = skus(big1);
            double good2 = skus(big2);
            best = max(best,good1);
            best = max(best,good2);
            if (good1 < good2) biglo = big1; else bighi = big2;
        }
        biglo -= 25; if (biglo < 0) biglo = 0;
        bighi += 25; if (bighi > K) bighi = K;
        for (int big=biglo; big<=bighi; ++big) {
            best = max(best,skus(big));
        }
        // and for good measure:
        for (int loop=0; loop<100; ++loop) {
            int big = rand()%(K+1);
            best = max(best,skus(big));
        }
        printf("Case #%d: %.10f\n",t,1.-best);
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
