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

#include <cstring>

long long A[22][22], WL[22][22], ES[22][22];
int R, C;
long long M;
bool done[22][22];
int dr[]={-1,1,0,0}, dc[]={0,0,-1,1};

bool all_empty() {
    FOR(r,1,R) FOR(c,1,C) if (A[r][c]) return false;
    return true;
}

int main() {
    int T; cin >> T;
    int step = (T+3)/4;
    int add = 0;
    REP(kolo,4) {
        char name[100];
        sprintf(name,"%d.in",kolo);
        ofstream fout(name);
        int curr = min(step,T);
        fout << add << endl;
        add += curr;
        fout << curr << endl;
        REP(t,curr) {
            cin >> R >> C >> M;
            fout << R << " " << C << " " << M << endl;
            FOR(r,1,R) {
                FOR(c,1,C) {
                    cin >> A[r][c];
                    fout << A[r][c] << (c==C ? "\n" : " ");
                }
            }
        }
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
