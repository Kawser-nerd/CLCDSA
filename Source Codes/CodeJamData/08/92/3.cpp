#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;

#define VV vector
#define PB push_back
#define ll long long
#define ld long double
#define REP(i,n) FOR(i,0,(n)-1)
#define FOR(i,a,b) for(int i = (a);i<=(b);++i)
#define FORD(i,a,b) for(int i = (a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SS(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define VI VV<int>
#define VS VV<string>
int COND = 1;
#define DB(x) { if (COND > 0) { COND--; REP (xxx, 1) cerr << __LINE__ << " " << #x << " " << x << endl; cerr.flush(); } }
int A[200][200];
int N, M;
int D[2][2];
int go(int i, int j) {
    if (!(i >= 0 && i < N && j >= 0 && j < M)) return 0;
    if (A[i][j]) return 0;
    A[i][j] = 1;
    int ret = 1;
    REP (d, 2) ret += go(i + D[d][0], j + D[d][1]);
    return ret;

}

int solve() {
    CLR(A, 0);
    cin >> N >> M;
    REP (i, 2) REP (j, 2) cin >> D[i][j];
    int SX, SY;
    cin >> SX >> SY;
    return go(SX, SY);
}

int main(int argc, char ** argv) { ios::sync_with_stdio(false);
    COND = argc >= 2 && argv[1][0] == 'q' ? (int)1e9 : 0;
    int T; cin >> T;
    FOR (my, 1, T) {
        DB(my);
        printf("Case #%d: %d\n", my, solve());
    }

    return 0;
}
