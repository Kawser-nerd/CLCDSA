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

bool over(vector<int> counts, int len) {
    deque<int> necessary;
    int optional=0;
    for (int x=1; x<=10001; ++x) {
        if (counts[x] < SIZE(necessary)) return false;
        counts[x] -= SIZE(necessary);
        int cont = min(optional,counts[x]);
        optional = cont;
        counts[x] -= cont;
        while (!necessary.empty() && necessary[0]==x-len+1) { ++optional; necessary.pop_front(); }
        while (counts[x]--) necessary.push_back(x);
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    FOR(t,1,T) {
        int N;
        cin >> N;
        vector<int> counts(10007,0);
        REP(n,N) { int x; cin >> x; ++counts[x]; }
        if (N==0) {
            printf("Case #%d: 0\n",t);
            continue;
        }
        int lo=1, hi=N+1;
        while (hi-lo > 1) {
            int med=(lo+hi)/2;
            if (over(counts,med)) lo=med; else hi=med;
        }
        printf("Case #%d: %d\n",t,lo);
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
