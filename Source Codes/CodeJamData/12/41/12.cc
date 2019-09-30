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

int main() {
    int T; cin >> T;
    FOR(t,1,T) {
        int N; cin >> N;
        vector<int> D(N+1), L(N+1);
        REP(n,N) cin >> D[n] >> L[n];
        cin >> D[N]; L[N] = 0;
        vector<int> B(N+1,-1);
        B[0] = D[0];
        deque<int> Q; Q.push_back(0);

        for (int c=1; c<=N; ++c) {
            while (!Q.empty() && D[Q.front()]+B[Q.front()] < D[c]) Q.pop_front();
            if (Q.empty()) break;
            B[c] = min(L[c], D[c] - D[Q.front()]);
            if (Q.empty()) Q.push_back(c);
            if (D[c]+B[c] > D[Q.back()]+B[Q.back()]) Q.push_back(c);
        }
        printf("Case #%d: %s\n",t,B[N]==-1?"NO":"YES");
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
