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
#define CLEAR(t) memset((t),0,sizeof(t))
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

typedef set<pair<int,int> > state;
int R, C;
char mapa[100][100];
int D;
int cave[10][2];
int dasa[100][100];

int dr[]={0,0,-1}, dc[]={-1,1,0};

state try_step(const state &from, int dr, int dc) {
    for (auto who : from) if (mapa[who.first+dr][who.second+dc]=='.' && !dasa[who.first+dr][who.second+dc]) return from;
    state answer;
    for (auto who : from) if (mapa[who.first+dr][who.second+dc]=='.') answer.insert(make_pair(who.first+dr,who.second+dc)); else answer.insert(who);
    return answer;
}

void solve(int cr, int cc) {
    // BFS to find the size
    int sajz = 1;
    CLEAR(dasa);
    dasa[cr][cc] = 1;
    queue<int> Q;
    Q.push(cr); Q.push(cc);
    while (!Q.empty()) {
        int r=Q.front(); Q.pop();
        int c=Q.front(); Q.pop();
        for (int d=0; d<3; ++d) {
            int nr=r+dr[d], nc=c+dc[d];
            if (mapa[nr][nc]=='#') continue;
            if (dasa[nr][nc]) continue;
            dasa[nr][nc] = 1;
            ++sajz;
            Q.push(nr); Q.push(nc);
        }
    }
    printf("%d ",sajz);
    // greedily construct the optimal moving sequence
    state MAM, CHCEM;
    CHCEM.insert( make_pair(cr,cc) );
    for (int r=0; r<R; ++r) for (int c=0; c<C; ++c) if (dasa[r][c]) MAM.insert( make_pair(r,c) );
    int kolo=0;
    while (true) {
        int topmost_row = cr;
        for (auto who : MAM) topmost_row = min( topmost_row, who.first );

        for (int c=0; c<C; ++c) MAM = try_step(MAM,0,-1);
        for (int c=0; c<C; ++c) {
            MAM = try_step(MAM,0,1);
            if (MAM == CHCEM) { printf("Lucky\n"); return; }
            MAM = try_step(MAM,1,0);
        }
        for (int c=0; c<C; ++c) {
            MAM = try_step(MAM,0,-1);
            if (MAM == CHCEM) { printf("Lucky\n"); return; }
            MAM = try_step(MAM,1,0);
        }

        int ntopmost_row = cr;
        for (auto who : MAM) ntopmost_row = min( ntopmost_row, who.first );
        // if (ntopmost_row == topmost_row) break; // certainly unlucky
        ++kolo; if (kolo==1000) break; // unlucky? :D
    }
    printf("Unlucky\n");
}

int main() {
    int T; scanf("%d ",&T);
    FOR(t,1,T) {
        scanf("%d %d ",&R,&C);
        REP(r,R) scanf("%s ",mapa[r]);
        D = 0;
        REP(r,R) REP(c,C) if (isdigit(mapa[r][c])) {
            int id = mapa[r][c]-'0';
            mapa[r][c]='.';
            D = max(D,id+1);
            cave[id][0]=r; cave[id][1]=c;
        }
        printf("Case #%d:\n",t);
        REP(d,D) { printf("%d: ",d); solve(cave[d][0],cave[d][1]); }
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
