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
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define SIZE(t) ((int)((t).size()))
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

int main() {
    int T;
    cin >> T;
    REP(t,T) {
        string S;
        cin >> S;
        reverse(S.begin(),S.end());
        int Q = 0;
        REP(i,SIZE(S)) if (S[i]=='?') ++Q;
        REP(qs,1<<Q) {
            long long cur = 0;
            int used=0;
            REP(i,SIZE(S)) {
                if (S[i]=='1') cur += 1LL << i;
                if (S[i]=='?') {
                    if (qs & (1<<used)) cur += 1LL << i;
                    ++used;
                }
            }
            long long hlp = (long long)sqrt(cur);
            bool ok=false;
            if ((hlp-1)*(hlp-1)==cur) ok=true;
            if ((hlp)*(hlp)==cur) ok=true;
            if ((hlp+1)*(hlp+1)==cur) ok=true;
            if (ok) {
                used=0;
                REP(i,SIZE(S)) if (S[i]=='?') {
                    if (qs & (1<<used)) S[i]='1'; else S[i]='0';
                    ++used;
                }
                reverse(S.begin(),S.end());
                cout << "Case #" << (t+1) << ": " << S << endl;
                break;
            }
        }
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
