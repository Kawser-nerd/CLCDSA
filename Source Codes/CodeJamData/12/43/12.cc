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
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

const int TOP = 1000000000;

vector<int> solve(vector<int> H) {
    int N = H.size()+1;
    vector<int> out(N,TOP);
    if (N <= 2) return out;
    int first = H[0];
    vector<int> H1(first-1), H2(N-1-first);
    for (int n=1; n<first; ++n) {
        if (H[n]>first) return vector<int>(0);
        H1[n-1] = H[n]-1;
    }
    for (int n=first; n<N-1; ++n) H2[n-first] = H[n]-first;
    vector<int> out1 = solve(H1);
    if (out1.empty()) return vector<int>(0);
    vector<int> out2 = solve(H2);
    if (out2.empty()) return vector<int>(0);
    for (int n=1; n<first; ++n) out[n] = out1[n-1] - first + n;
    for (int n=first; n<N; ++n) out[n] = out2[n-first];
    return out;
}

int main() {
    int T; cin >> T;
    FOR(t,1,T) {
        int N; cin >> N;
        vector<int> H(N-1);
        for (int n=0; n<N-1; ++n) { cin >> H[n]; --H[n]; }
        vector<int> out = solve(H);
        if (out.empty()) {
            printf("Case #%d: Impossible\n",t);
        } else {
            printf("Case #%d:",t);
            for (int n=0; n<N; ++n) printf(" %d",out[n]);
            printf("\n");
        }
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
