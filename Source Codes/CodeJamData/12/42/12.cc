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
#define SQR(x) ((x)*(x))
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

inline double drand(double max) { return (max*rand())/RAND_MAX; }

int N;
double W, L;
vector< pair<double,int> > C;

vector< pair<double,double> > ries() {
    vector< pair<double,double> > answer(N);
    answer[0] = make_pair(0,0);
    for (int n=1; n<N; ++n) {
        bool found = false;
        for (int pokus=0; pokus<10000; ++pokus) {
            double w = drand(W), l = drand(L);
            bool ok=true;
            for (int i=0; i<n; ++i) if (SQR(w-answer[i].first) + SQR(l-answer[i].second) < SQR( C[n].first+C[i].first )) { ok=false; break; }
            if (ok) { answer[n]=make_pair(w,l); found=true; break; }
        }
        if (!found) return vector< pair<double,double> >(0);
    }
    vector< pair<double,double> > answer2(N);
    for (int n=0; n<N; ++n) answer2[ C[n].second ] = answer[n];
    return answer2;
};

int main() {
    int T; cin >> T;
    FOR(t,1,T) {
        cin >> N;
        cin >> W >> L;
        C.clear(); C.resize(N);
        for (int n=0; n<N; ++n) { double r; cin >> r; C[n]=make_pair(r,n); }
        sort(C.begin(),C.end());
        reverse(C.begin(),C.end());
        while (true) {
            vector< pair<double,double> > answer = ries();
            if (!answer.empty()) {
                for (int a=0; a<N; ++a) { 
                    assert( 0<=answer[a].first && answer[a].first<=W );
                    assert( 0<=answer[a].second && answer[a].second<=L );
                }
                printf("Case #%d:",t);
                for (int n=0; n<N; ++n) printf(" %.9f %.9f",answer[n].first,answer[n].second);
                printf("\n");
                break;
            }
            cerr << "restart needed" << endl;
        }
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
