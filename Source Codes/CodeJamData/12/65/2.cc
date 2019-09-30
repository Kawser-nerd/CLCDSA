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
        vector<int> L(N-1), R(N-1);
        REP(n,N-1) { cin >> L[n] >> R[n]; --L[n]; --R[n]; }
        int state = 0;
        int steps = 0;
        int bits = 1 << (N-1);
        vector<bool> seen(N*bits,false);
        while (true) {
            if (seen[state]) { steps=-1; break; }
            seen[state] = true;
            int room = (state >> (N-1));
            int flags = state & (bits-1);
            ++steps;
            int nroom;
            if (flags & 1<<room) {
                //cout << room << " " << flags << " " << "right" << endl;
                nroom=R[room];
            } else {
                //cout << room << " " << flags << " " << "left" << endl;
                nroom=L[room];
            }
            if (nroom==N-1) break;
            flags ^= 1 << room;
            state = (nroom << (N-1)) | flags;
        }
        if (steps==-1) {
            printf("Case #%d: Infinity\n",t);
        } else {
            printf("Case #%d: %d\n",t,steps);
        }
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
