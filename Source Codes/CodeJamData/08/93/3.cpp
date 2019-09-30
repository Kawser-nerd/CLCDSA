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

int R, C;
int A[101][101];

int TR = -1;
#define X first
#define Y second


map <int, int> DP[101];

#define bit(ma, i, j) (((ma) & (1 << (i) * 6 + (j))))

int solve() {
    REP (i, 101) DP[i].clear();
    CLR(A, 0);
    cin >> R >> C;
    REP (i, R) REP (j, C) 
        cin >> A[i+2][j];
    DP[0][0] = 0;
    DB(R<<" "<<C);

    TR = R / 2 + 2; // 1, R + 2 // nc

    REP (i, R + 4) {
        FORE (it, DP[i]) {
            DB(i<<" "<<it->X<<" "<<it->Y);
            REP (ne, 1 << C) {
                if ((i <= 0 || i >= R + 1) && ne != 0) continue;
                bool ok = 1;
                int nmask = it->X | (ne << 12);
                REP (j, C) {
                    int cnt = A[i][j];
                    FOR (lev, 0, 2) FOR (nj, j -1, j + 1) {
                        if (bit(nmask, lev, nj)) {
                            cnt--;
                        }
                    }
                    if (cnt != 0) ok = 0;
                    DB(j<<" "<<cnt<<" "<<A[i][j]<<" "<<nmask);
                }
                if (i <= 1 || i >= R + 2) ok = 1;
                if (ok) {
                    int cur = it->Y;
                    if (i == TR) cur = max(cur, __builtin_popcount(it->X >> 6));
                    DB(i<<" "<<nmask<<" "<<cur<<" "<<TR<<" "<<(it->X >> 6) <<" "<<it->X); 
                    DP[i+1][nmask >> 6] = max(DP[i+1][nmask >> 6], cur);
                }
            }
        }
    }
    int ret = 0;
    FORE (it, DP[R + 4]) ret = max(ret, it->Y);
    return ret;
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
