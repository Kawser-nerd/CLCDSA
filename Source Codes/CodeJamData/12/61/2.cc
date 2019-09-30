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

struct zombie {
    int x,y,m;
    zombie(int x, int y, int m) : x(x), y(y), m(m) { }
};

bool operator< (const zombie &A, const zombie &B) { return A.m < B.m; }

#define INF 1234567890

int best[110][110];
int dist[110][110];

int zdist(const zombie &A, const zombie &B) { return 100*max(abs(B.x-A.x),abs(B.y-A.y)); }

int main() {
    int T; cin >> T;
    FOR(t,1,T) {
        int N; cin >> N;
        vector<zombie> Z;
        Z.push_back(zombie(0,0,-750));
        REP(n,N) { int x,y,m; cin >> x >> y >> m; Z.push_back(zombie(x,y,m)); }
        sort(Z.begin(),Z.end());
        REP(i,N+1) REP(j,N+1) dist[i][j] = zdist(Z[i],Z[j]);
        REP(i,N+2) REP(j,N+2) best[i][j]=INF;
        best[0][0] = 0;
        while (true) {
            bool zmena = false;
            for (int n=1; n<=N; ++n) {
                // try smashing zombie n after zombie i
                for (int i=0; i<=N; ++i) if (i!=n) {
                    for (int s=0; s<=n; ++s) {
                        if (best[i][s]==INF) continue;
                        int travel_time = dist[i][n];
                        if (i!=0 || s!=0) if (travel_time <= 750) travel_time = 750;
                        int arrival_time = best[i][s] + travel_time;
                        if (arrival_time < Z[n].m) arrival_time = Z[n].m;
                        if (arrival_time > Z[n].m+1000) continue;
                        if (arrival_time < best[n][s+1]) {
                            zmena = true;
                            best[n][s+1] = arrival_time;
                        }
                    }
                }
            }
            if (!zmena) break;
        }
        int ans = 0;
        REP(i,N+2) REP(j,N+2) if (best[i][j] != INF) ans = max( ans, j );
        printf("Case #%d: %d\n",t,ans);
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
